#!/usr/bin/env python3
"""
╔══════════════════════════════════════════════════════════════╗
║   RTL AUTO-FIX PIPELINE  ×  COGNIX (ACI)                    ║
║   Simulate → Yosys Pre-Synth → OpenSTA Timing → Cognix fix  ║
╚══════════════════════════════════════════════════════════════╝

HOW IT WORKS:
  1.  Auto-detects your .sv files from the test/ folder
  2.  Runs Verilator simulation
  3.  If PASSED → runs Yosys pre-synthesis checks
      3a. If Yosys finds blocking issues → Cognix fixes RTL
      3b. If Yosys clean → runs OpenSTA timing analysis
          3b-i.  If timing violations → Cognix restructures RTL
          3b-ii. If timing clean → ALL CHECKS PASSED ✅
  4.  If sim FAILED → formats prompt for Cognix (with Yosys context)
  5.  Copies prompt to clipboard automatically
  6.  Opens Cognix chat in VS Code
  7.  You paste (Cmd+V) → Enter → Cognix replies with fixed code
  8.  Click the "Apply" button in Cognix → file gets overwritten
  9.  Script AUTO-DETECTS the file save and re-runs the full suite
  10. Loops until SIM + YOSYS + TIMING all pass

Pipeline stages (all optional, gracefully skipped if tool missing):
  Verilator  — functional simulation (required)
  Yosys      — gate-level pre-synthesis checks + netlist generation
  OpenSTA    — static timing analysis on the Yosys netlist

Usage:
    python3 auto_fix_cognix.py
    python3 auto_fix_cognix.py --top my_top_module
    python3 auto_fix_cognix.py --skip-yosys
    python3 auto_fix_cognix.py --skip-sta
    python3 auto_fix_cognix.py --clock-period 4.0   <- target clock (ns)
    python3 auto_fix_cognix.py --liberty /path/to/my.lib

OpenSTA install (build from source):
    git clone https://github.com/parallaxsw/OpenSTA.git
    cd OpenSTA && mkdir build && cd build
    cmake .. && make -j$(nproc)
    sudo make install          # installs 'sta' binary to /usr/local/bin

    OR via package manager:
    brew install opensta       # macOS (Homebrew)
    guix install opensta       # Linux (Guix)

Liberty file (required for STA):
    Set env var: export LIBERTY_PATH=/path/to/your.lib
    OR let the script auto-download NanGate45 from OpenROAD-flow-scripts.
"""

import os
import re
import sys
import json
import time
import shutil
import argparse
import subprocess
from pathlib import Path
from datetime import datetime

# ─── COLORS ──────────────────────────────────────────────────────────────────

class C:
    RED     = "\033[91m"
    GREEN   = "\033[92m"
    YELLOW  = "\033[93m"
    BLUE    = "\033[94m"
    CYAN    = "\033[96m"
    MAGENTA = "\033[95m"
    BOLD    = "\033[1m"
    RESET   = "\033[0m"

def banner(msg, color=C.CYAN):
    w = 66
    print(f"\n{color}{C.BOLD}{'═'*w}")
    print(f"  {msg}")
    print(f"{'═'*w}{C.RESET}\n")

def log(tag, msg, color=C.RESET):
    ts = datetime.now().strftime("%H:%M:%S")
    print(f"{color}{C.BOLD}[{ts}][{tag}]{C.RESET} {msg}")

# ─── AUTO FILE DETECTION ─────────────────────────────────────────────────────

def detect_sv_files() -> tuple[str, str]:
    """
    Scans the test/ folder for exactly 2 .sv files.
    Identifies TB (has 'tb' in name, or contains initial/timescale)
    vs RTL. Returns (rtl_file, tb_file) as absolute path strings.
    """
    script_dir = Path(__file__).parent.resolve()
    test_dir   = script_dir / "test"

    if not test_dir.exists():
        log("ERROR", f"'test/' folder not found at: {test_dir}", C.RED)
        log("ERROR", "Create a 'test/' folder next to this script and put your .sv files in it.", C.YELLOW)
        sys.exit(1)

    sv_files = sorted(test_dir.glob("*.sv"))

    if len(sv_files) == 0:
        log("ERROR", f"No .sv files found in {test_dir}", C.RED)
        sys.exit(1)
    if len(sv_files) == 1:
        log("ERROR", "Only 1 .sv file found in test/ — need both RTL and TB.", C.RED)
        sys.exit(1)
    if len(sv_files) > 2:
        log("ERROR", f"Found {len(sv_files)} .sv files in test/ — expected exactly 2:", C.RED)
        for f in sv_files:
            print(f"    {C.YELLOW}→ {f.name}{C.RESET}")
        sys.exit(1)

    tb_candidates  = [f for f in sv_files if "tb" in f.stem.lower()]
    rtl_candidates = [f for f in sv_files if "tb" not in f.stem.lower()]

    if len(tb_candidates) == 1 and len(rtl_candidates) == 1:
        tb_file  = str(tb_candidates[0])
        rtl_file = str(rtl_candidates[0])
    else:
        log("DETECT", "Can't tell TB/RTL by filename — checking contents...", C.YELLOW)
        tb_file  = None
        rtl_file = None
        for f in sv_files:
            content = f.read_text()
            if "initial begin" in content or "`timescale" in content:
                tb_file = str(f)
            else:
                rtl_file = str(f)

        if not tb_file or not rtl_file:
            log("DETECT", "Falling back to alphabetical: first=RTL, second=TB", C.YELLOW)
            rtl_file = str(sv_files[0])
            tb_file  = str(sv_files[1])

    log("DETECT", f"RTL file : {Path(rtl_file).name}", C.CYAN)
    log("DETECT", f"TB  file : {Path(tb_file).name}", C.CYAN)
    return rtl_file, tb_file


def detect_top_module(tb_file: str) -> str:
    """Reads the TB file and returns the first module name found."""
    content = Path(tb_file).read_text()
    match = re.search(r'^\s*module\s+(\w+)', content, re.MULTILINE)
    if match:
        top = match.group(1)
        log("DETECT", f"Top module (TB): {top}", C.CYAN)
        return top
    log("ERROR", "Could not auto-detect top module. Use --top to specify it.", C.RED)
    sys.exit(1)


def detect_rtl_module(rtl_file: str) -> str:
    """
    Reads the RTL file and returns the first module name found.
    Used for Yosys and OpenSTA — must be the RTL module, NOT the TB.
    Falls back to the filename stem if no module declaration found.
    """
    content = Path(rtl_file).read_text()
    match = re.search(r'^\s*module\s+(\w+)', content, re.MULTILINE)
    if match:
        rtl_top = match.group(1)
        log("DETECT", f"RTL module (Yosys/STA): {rtl_top}", C.CYAN)
        return rtl_top
    fallback = Path(rtl_file).stem
    log("DETECT", f"Could not detect RTL module name — falling back to: {fallback}", C.YELLOW)
    return fallback


def detect_clock_port(rtl_file: str) -> str | None:
    """
    Heuristic: scan the RTL module port list for a clock signal.
    Matches common naming conventions: clk, clock, clk_i, sys_clk, etc.
    Returns the port name or None if not found (combinational block).
    """
    content = Path(rtl_file).read_text()
    clk_patterns = [
        r'\binput\b.*?\b(clk\w*)\b',
        r'\binput\b.*?\b(clock\w*)\b',
        r'\binput\b.*?\b(\w*clk)\b',
        r'\binput\b.*?\b(\w*clock)\b',
    ]
    for pat in clk_patterns:
        m = re.search(pat, content, re.IGNORECASE)
        if m:
            port = m.group(1)
            log("DETECT", f"Clock port heuristic: '{port}'", C.CYAN)
            return port
    log("DETECT", "No clock port detected — STA will use virtual clock.", C.YELLOW)
    return None

# ─── CLIPBOARD ───────────────────────────────────────────────────────────────

def copy_to_clipboard(text: str):
    try:
        subprocess.run(["pbcopy"], input=text.encode(), check=True)
        return True
    except Exception as e:
        log("CLIP", f"Could not copy to clipboard: {e}", C.YELLOW)
        return False

# ─── OPEN COGNIX IN VSCODE ───────────────────────────────────────────────────

def open_cognix_chat():
    try:
        subprocess.run(
            ["code", "--command", "workbench.panel.chat.view.copilot.focus"],
            capture_output=True
        )
    except Exception:
        pass

# ─── SIMULATION ──────────────────────────────────────────────────────────────

def run_simulation(rtl_file: str, tb_file: str, top: str) -> dict:
    log("SIM", f"Compiling {Path(rtl_file).name} + {Path(tb_file).name}...", C.BLUE)

    compile_cmd = [
        "verilator", "--binary", "--timing", "--trace",
        "-Wno-WIDTHTRUNC", "-Wno-DECLFILENAME", "-Wno-fatal", "--assert",
        rtl_file, tb_file,
        "--top-module", top,
        "-o", "sim_autofix"
    ]

    compile_result = subprocess.run(compile_cmd, capture_output=True, text=True)

    if compile_result.returncode != 0:
        log("COMPILE", "FAILED ✗", C.RED)
        errors = parse_errors(compile_result.stderr + compile_result.stdout)
        return {
            "phase":  "compile",
            "passed": False,
            "output": compile_result.stderr + compile_result.stdout,
            "errors": errors,
        }

    log("COMPILE", "OK ✓", C.GREEN)
    log("SIM", "Running...", C.BLUE)

    sim_result = subprocess.run(
        ["./obj_dir/sim_autofix", "+trace"],
        capture_output=True, text=True
    )

    output = sim_result.stdout + sim_result.stderr
    passed = "TEST PASSED" in output and "TEST FAILED" not in output
    errors = parse_errors(output)

    if passed:
        log("SIM", "TEST PASSED ✓", C.GREEN)
    else:
        log("SIM", f"TEST FAILED — {len(errors)} error(s) ✗", C.RED)
        for e in errors[:6]:
            print(f"    {C.RED}→ {e}{C.RESET}")

    return {
        "phase":  "sim",
        "passed": passed,
        "output": output,
        "errors": errors,
    }

def parse_errors(output: str) -> list:
    errors = []
    for line in output.splitlines():
        if any(k in line for k in ["ERROR", "%Error", "error:", "FAILED", "Assertion"]):
            errors.append(line.strip())
    return errors

# ─── YOSYS PRE-SYNTHESIS CHECKS ──────────────────────────────────────────────

YOSYS_BLOCKING_PATTERNS = [
    ("ERROR:",             ["Executing", "Removed", "Finding"]),
    ("Latch inferred",     []),
    ("combinatorial loop", []),
    ("multiple drivers",   []),
    ("Found no clocks",    []),
    ("is not used",        ["Removed", "Finding", "Executing"]),
]

YOSYS_WARNING_PATTERNS = [
    ("Warning:",           ["Executing", "Removed", "Finding", "OPT_CLEAN"]),
    ("undriven",           ["Removed", "Finding", "Executing"]),
    ("width mismatch",     []),
    ("truncated",          ["Removed", "Finding"]),
    ("signed/unsigned",    []),
]


def _line_matches(line: str, pattern_list: list) -> bool:
    lo = line.lower()
    for must_have, must_not in pattern_list:
        if must_have.lower() in lo:
            if not any(excl.lower() in lo for excl in must_not):
                return True
    return False


def parse_yosys_output(output: str) -> dict:
    blocking = []
    warnings = []
    stats    = []

    for line in output.splitlines():
        stripped = line.strip()
        if not stripped:
            continue
        if _line_matches(stripped, YOSYS_BLOCKING_PATTERNS):
            blocking.append(stripped)
        elif _line_matches(stripped, YOSYS_WARNING_PATTERNS):
            warnings.append(stripped)
        elif any(k in stripped for k in ["Number of cells:", "Chip area", "Number of wires",
                                          "Number of wire bits", "Estimated number"]):
            stats.append(stripped)

    return {
        "clean":    len(blocking) == 0,
        "blocking": blocking,
        "warnings": warnings,
        "stats":    stats,
        "raw":      output,
    }


def run_yosys_checks(rtl_file: str, rtl_top: str) -> dict | None:
    """
    Runs Yosys pre-synthesis on the RTL file (NOT the testbench).
    Also emits a gate-level netlist (_sta_netlist_<top>.v) for OpenSTA.
    Returns parsed result dict or None if Yosys is not installed.
    """
    if not shutil.which("yosys"):
        log("YOSYS", "yosys not found — skipping pre-synthesis checks.", C.YELLOW)
        log("YOSYS", "Install: brew install yosys  |  apt install yosys", C.YELLOW)
        return None

    log("YOSYS", f"Running pre-synthesis checks on {Path(rtl_file).name} (top: {rtl_top})...", C.MAGENTA)

    # Gate-level netlist written here for OpenSTA consumption
    netlist_path = str(Path(rtl_file).parent / f"_sta_netlist_{rtl_top}.v")

    yosys_script = f"""
read_verilog -sv {rtl_file}
hierarchy -check -top {rtl_top}
proc
flatten
synth -noabc -top {rtl_top}
check -assert
stat
write_verilog -noattr {netlist_path}
"""

    result = subprocess.run(
        ["yosys", "-p", yosys_script],
        capture_output=True, text=True
    )

    combined = result.stdout + result.stderr
    parsed   = parse_yosys_output(combined)

    if result.returncode != 0 and parsed["clean"]:
        parsed["blocking"].append(
            f"Yosys exited with error code {result.returncode} — check run log for details"
        )
        parsed["clean"] = False

    # Track where the netlist landed
    parsed["netlist_path"] = netlist_path if Path(netlist_path).exists() else None

    if parsed["clean"]:
        log("YOSYS", "Pre-synthesis: CLEAN ✓", C.GREEN)
    else:
        log("YOSYS", f"Pre-synthesis: {len(parsed['blocking'])} blocking issue(s) found ✗", C.RED)
        for issue in parsed["blocking"][:8]:
            print(f"    {C.RED}→ {issue}{C.RESET}")

    if parsed["warnings"]:
        log("YOSYS", f"{len(parsed['warnings'])} warning(s):", C.YELLOW)
        for w in parsed["warnings"][:6]:
            print(f"    {C.YELLOW}⚠  {w}{C.RESET}")

    if parsed["stats"]:
        log("YOSYS", "Design stats:", C.CYAN)
        for s in parsed["stats"]:
            print(f"    {C.CYAN}   {s}{C.RESET}")

    return parsed

# ─── OPENSTA TIMING ANALYSIS ─────────────────────────────────────────────────
#
# OpenSTA (https://github.com/The-OpenROAD-Project/OpenSTA) is an open-source
# gate-level static timing analyser developed by Parallax Software and used
# inside the OpenROAD physical design flow.
#
# WHAT IT DOES IN THIS PIPELINE:
#   After Yosys produces a gate-level netlist, OpenSTA reads that netlist
#   together with a Liberty (.lib) cell library and clock/IO constraints,
#   then reports:
#     • Worst Negative Slack (WNS) — how much the design misses timing
#     • Total Negative Slack (TNS) — cumulative timing debt across all paths
#     • Full critical-path breakdowns — startpoint → endpoint with delays
#
#   If WNS < STA_WNS_THRESHOLD the pipeline fires a Cognix prompt asking
#   it to restructure the RTL to reduce critical-path depth.
#
# BINARY NAME:
#   OpenSTA installs as 'sta' (cmake install) or 'opensta' (some distros).
#   We probe for both.
#
# INVOCATION MODEL:
#   OpenSTA reads TCL from stdin when called with:
#       sta -no_init -exit
#   -no_init  → skip the user's ~/.sta init file (reproducible behaviour)
#   -exit     → exit after reading stdin (belt-and-suspenders with TCL 'exit')
#
# KEY TCL COMMANDS:
#   read_liberty  <lib>                         load cell timing models
#   read_verilog  <netlist.v>                   parse gate-level netlist
#   link_design   <top>                         elaborate the design
#   create_clock  -name clk -period <ns> \
#                 [get_ports <port>]            define primary clock
#   set_input_delay  <ns> -clock clk            IO timing margins
#   set_output_delay <ns> -clock clk
#   report_wns                                  scalar worst negative slack
#   report_tns                                  scalar total negative slack
#   report_checks -path_delay max \             full path breakdown
#     -fields {slew cap input_pins net} \
#     -digits 3 -max_paths 5
#   exit                                        terminate OpenSTA
#
# LIBERTY FILE:
#   Required for cell delay models.  Defaults to NanGate45 (auto-downloaded).
#   Override: export LIBERTY_PATH=/your/lib  OR  --liberty /path/to/lib
#
# ─────────────────────────────────────────────────────────────────────────────

LIBERTY_CACHE = Path.home() / ".cache" / "rtl_autofix" / "nangate45.lib"
LIBERTY_URL   = (
    "https://raw.githubusercontent.com/The-OpenROAD-Project/"
    "OpenROAD-flow-scripts/master/flow/platforms/nangate45/lib/"
    "NangateOpenCellLibrary_typical.lib"
)

# WNS worse than this (in ns) triggers a Cognix timing-fix prompt
STA_WNS_THRESHOLD = -0.1   # -100 ps


def ensure_liberty_file(liberty_override: str | None = None) -> str | None:
    """
    Resolves a Liberty .lib file for OpenSTA in priority order:
      1. --liberty CLI flag
      2. LIBERTY_PATH environment variable
      3. Local cache  (~/.cache/rtl_autofix/nangate45.lib)
      4. One-time auto-download of NanGate45 from OpenROAD-flow-scripts

    Returns the file path string, or None if unavailable (STA skipped).
    """
    if liberty_override and Path(liberty_override).exists():
        log("STA", f"Liberty (--liberty flag): {liberty_override}", C.CYAN)
        return liberty_override

    env_lib = os.environ.get("LIBERTY_PATH")
    if env_lib and Path(env_lib).exists():
        log("STA", f"Liberty (LIBERTY_PATH env): {env_lib}", C.CYAN)
        return env_lib

    if LIBERTY_CACHE.exists():
        log("STA", f"Liberty (cached): {LIBERTY_CACHE}", C.CYAN)
        return str(LIBERTY_CACHE)

    log("STA", "Liberty file not found — attempting auto-download (NanGate45)...", C.YELLOW)
    try:
        LIBERTY_CACHE.parent.mkdir(parents=True, exist_ok=True)
        dl = subprocess.run(
            ["curl", "-fsSL", "--max-time", "30", "-o", str(LIBERTY_CACHE), LIBERTY_URL],
            capture_output=True, text=True
        )
        if dl.returncode == 0 and LIBERTY_CACHE.exists() and LIBERTY_CACHE.stat().st_size > 1000:
            log("STA", f"Liberty cached → {LIBERTY_CACHE}", C.GREEN)
            return str(LIBERTY_CACHE)
        else:
            log("STA", "Download failed. Set LIBERTY_PATH or use --liberty.", C.YELLOW)
            if LIBERTY_CACHE.exists():
                LIBERTY_CACHE.unlink()
            return None
    except FileNotFoundError:
        log("STA", "curl not found — cannot auto-download Liberty.", C.YELLOW)
        return None
    except Exception as e:
        log("STA", f"Download error: {e}", C.YELLOW)
        return None


def _find_sta_binary() -> str | None:
    """Returns 'sta', 'opensta', or None depending on what's on PATH."""
    for candidate in ("sta", "opensta"):
        if shutil.which(candidate):
            return candidate
    return None


def _generate_sta_tcl(netlist_path: str, rtl_top: str, liberty_path: str,
                       clock_port: str | None, clock_period_ns: float) -> str:
    """
    Generates the OpenSTA TCL script piped to stdin.

    Clock strategy:
      • If a real clock port was found → create_clock on that port.
      • If no clock port (combinational design) → create a virtual clock
        named 'vclk' used only for I/O delay constraints.

    I/O delay margin = 20% of clock period (conservative default).
    """
    io_delay = round(clock_period_ns * 0.20, 3)

    if clock_port:
        clock_cmd = (
            f"create_clock -name clk -period {clock_period_ns:.3f} "
            f"[get_ports {clock_port}]"
        )
        io_clock_ref = "clk"
    else:
        # Virtual clock for combinational or clock-less blocks
        clock_cmd    = f"create_clock -name vclk -period {clock_period_ns:.3f}"
        io_clock_ref = "vclk"

    return f"""# ── OpenSTA TCL script — auto-generated by auto_fix_cognix.py ──
# Reference: https://github.com/The-OpenROAD-Project/OpenSTA

# 1. Load Liberty timing models
read_liberty {liberty_path}

# 2. Load Yosys gate-level netlist
read_verilog {netlist_path}

# 3. Elaborate / link the top-level design
link_design {rtl_top}

# 4. Clock constraints
{clock_cmd}

# 5. I/O timing margins ({io_delay} ns = 20% of {clock_period_ns:.3f} ns period)
set_input_delay  {io_delay} -clock {io_clock_ref} [all_inputs]
set_output_delay {io_delay} -clock {io_clock_ref} [all_outputs]

# 6. Reports
report_wns
report_tns

# Full path breakdown: max-delay (setup) analysis, top-5 paths
report_checks \\
    -path_delay max \\
    -fields {{slew capacitance input_pins net}} \\
    -digits 3 \\
    -max_paths 5

exit
"""


def parse_sta_output(output: str) -> dict:
    """
    Parses OpenSTA stdout/stderr into structured metrics.

    Recognises both output formats:
      "wns -1.234"             from report_wns
      "tns -5.678"             from report_tns
      "Worst Slack -1.234"     alternative header
      "slack (VIOLATED)"       path detail lines

    Returns:
      wns   (float, ns)  — Worst Negative Slack; 0.0 if no violations
      tns   (float, ns)  — Total Negative Slack; 0.0 if no violations
      paths (list[str])  — up to 20 violating path lines
      clean (bool)       — True if WNS >= STA_WNS_THRESHOLD
      raw   (str)        — full combined output for logging/prompt injection
    """
    wns   = 0.0
    tns   = 0.0
    paths = []

    for line in output.splitlines():
        s = line.strip()
        if not s:
            continue

        if re.search(r'\bwns\b', s, re.IGNORECASE) or "Worst Slack" in s:
            m = re.search(r'(-?\d+\.\d+)', s)
            if m:
                wns = float(m.group(1))

        elif re.search(r'\btns\b', s, re.IGNORECASE):
            m = re.search(r'(-?\d+\.\d+)', s)
            if m:
                tns = float(m.group(1))

        elif any(k in s for k in ["VIOLATED", "slack (VIOLATED)", "Startpoint:",
                                   "Endpoint:", "data arrival time",
                                   "data required time"]):
            paths.append(s)

    return {
        "clean": wns >= STA_WNS_THRESHOLD,
        "wns":   wns,
        "tns":   tns,
        "paths": paths[:20],
        "raw":   output,
    }


def run_opensta(netlist_path: str, rtl_top: str, liberty_path: str,
                clock_port: str | None, clock_period_ns: float) -> dict | None:
    """
    Runs OpenSTA static timing analysis on the Yosys gate-level netlist.

    Invocation:
        sta -no_init -exit   (TCL piped via stdin)

    Returns parsed timing dict, or None if:
      • OpenSTA binary not found on PATH
      • Gate-level netlist does not exist (Yosys failed)
      • OpenSTA times out (> 120 s)
    """
    sta_bin = _find_sta_binary()
    if sta_bin is None:
        log("STA", "OpenSTA not found — skipping timing analysis.", C.YELLOW)
        log("STA", "Build: https://github.com/parallaxsw/OpenSTA", C.YELLOW)
        log("STA", "OR:    brew install opensta  |  guix install opensta", C.YELLOW)
        return None

    if not Path(netlist_path).exists():
        log("STA", "Gate-level netlist missing — Yosys may have failed. Skipping STA.", C.YELLOW)
        return None

    log("STA", (
        f"Running OpenSTA [{sta_bin}] on {Path(netlist_path).name}  "
        f"top={rtl_top}  period={clock_period_ns:.2f}ns"
    ), C.MAGENTA)

    if clock_port:
        log("STA", f"Clock port: '{clock_port}'  ({1000/clock_period_ns:.0f} MHz target)", C.CYAN)
    else:
        log("STA", "No clock port found — using virtual clock.", C.YELLOW)

    tcl_script = _generate_sta_tcl(
        netlist_path    = netlist_path,
        rtl_top         = rtl_top,
        liberty_path    = liberty_path,
        clock_port      = clock_port,
        clock_period_ns = clock_period_ns,
    )

    try:
        result = subprocess.run(
            [sta_bin, "-no_init", "-exit"],
            input          = tcl_script,
            capture_output = True,
            text           = True,
            timeout        = 120,
        )
    except subprocess.TimeoutExpired:
        log("STA", "OpenSTA timed out (120 s) — skipping.", C.YELLOW)
        return None
    except FileNotFoundError:
        log("STA", f"Could not execute '{sta_bin}' — is it on PATH?", C.RED)
        return None

    combined = result.stdout + result.stderr
    parsed   = parse_sta_output(combined)

    # ── Print summary ──
    status_str = "CLEAN ✓" if parsed["clean"] else "VIOLATIONS FOUND ✗"
    col        = C.GREEN   if parsed["clean"] else C.RED
    log("STA", (
        f"WNS: {parsed['wns']:.3f} ns   "
        f"TNS: {parsed['tns']:.3f} ns   "
        f"{status_str}"
    ), col)

    if not parsed["clean"]:
        for p in parsed["paths"][:6]:
            print(f"    {C.RED}→ {p}{C.RESET}")

    # ── Warn on suspicious empty/error output ──
    if not combined.strip():
        log("STA", "OpenSTA produced no output — check Liberty/netlist compatibility.", C.YELLOW)
    elif result.returncode != 0 and "VIOLATED" not in combined:
        log("STA", "OpenSTA returned non-zero exit — timing results may be partial.", C.YELLOW)
        for line in combined.splitlines():
            if re.search(r'\berror\b', line, re.IGNORECASE):
                print(f"    {C.YELLOW}⚠  {line.strip()}{C.RESET}")

    return parsed

# ─── PROMPT BUILDER ──────────────────────────────────────────────────────────

RTL_CONSTRAINTS = """
━━━ PRODUCTION RTL QUALITY CONSTRAINTS (MANDATORY) ━━━

These constraints are node-independent and universally mandatory.
Functional correctness, clock/reset integrity, CDC/RDC safety, protocol
compliance, DFT preservation, synthesis legality, tool compatibility,
micro-architectural stability, formal equivalence, safety mechanism
preservation, and verification integrity hold at every node (14nm → 2nm).
What changes with node scaling is physical sensitivity severity
(interconnect delay, congestion, power density, EM/IR, variability) —
NOT the logical correctness requirements.

FUNCTIONAL & VERIFICATION INTEGRITY
- Preserve bit-accurate functional behavior and identical reset sequencing
- FSM transitions, protocol timing, and clock domain structure must be unchanged
- Must pass formal equivalence checking against the golden RTL
- All assertions, coverage points, and safety properties must be preserved
- No degradation in constrained-random verification or functional/code coverage

SAFETY & FAULT DETECTION
- Preserve ECC, parity, redundancy logic, watchdogs, and diagnostic structures
- No reduction in fault-detection capability or safety compliance assumptions

SYNTHESIS & DFT LEGALITY
- Must remain fully synthesizable under the approved toolchain
- Preserve scan architecture, test modes, BIST logic, and JTAG connectivity
- Avoid unintended memory or DSP inference

LOW-POWER INTENT (UPF/CPF)
- Maintain isolation cells, retention registers, power domain boundaries,
  and level-shifter assumptions
- Preserve clock-gating intent; minimize glitching and unnecessary switching
- Avoid large synchronous switching spikes that worsen IR drop or thermal hotspots

CDC / RDC / RESET INTEGRITY
- No new clock-domain crossings, reset-domain crossings, or metastability risks
- Maintain reset dominance and sequencing guarantees

TIMING & AREA
- Reduce or maintain critical path depth; control fanout
- Minimize long combinational cones; remain retiming-friendly
- Eliminate redundant logic safely
- Preserve architectural latency and throughput unless explicitly permitted to change
- Avoid transformations that alter back-pressure, pipeline balance, or handshake semantics

LINT & FLOW COMPATIBILITY
- Output must be lint-clean, CDC-clean, RDC-clean
- Compatible with synthesis, STA, formal, DFT, and physical implementation flows
- All structural changes must be traceable and justifiable in design review

NODE-SPECIFIC GUIDANCE (5nm and below)
- Guide restructuring to mitigate wire-delay dominance, congestion,
  EM sensitivity, and power density
- Physical optimization is layered ON TOP of correctness — never a replacement
"""


def build_cognix_prompt(rtl_code: str, tb_code: str, sim_result: dict, iteration: int,
                         rtl_file: str, tb_file: str,
                         yosys_result: dict | None = None,
                         sta_result:   dict | None = None) -> str:
    error_lines = "\n".join(sim_result.get("errors", [])[:20])
    full_output = sim_result.get("output", "")[:2000]
    phase       = sim_result.get("phase", "sim")
    rtl_name    = Path(rtl_file).name
    tb_name     = Path(tb_file).name

    yosys_section = ""
    if yosys_result is not None:
        status       = "CLEAN ✓" if yosys_result["clean"] else "ISSUES FOUND ✗"
        blocking_txt = "\n".join(yosys_result["blocking"][:15]) or "None"
        warnings_txt = "\n".join(yosys_result["warnings"][:10]) or "None"
        stats_txt    = "\n".join(yosys_result["stats"])         or "Not available"
        yosys_section = f"""
━━━ YOSYS PRE-SYNTHESIS REPORT (status: {status}) ━━━

BLOCKING ISSUES (must fix before layout):
{blocking_txt}

WARNINGS (should fix):
{warnings_txt}

DESIGN STATS (gate-level):
{stats_txt}

"""

    sta_section = ""
    if sta_result is not None:
        sta_status = "CLEAN ✓" if sta_result["clean"] else "VIOLATIONS FOUND ✗"
        paths_txt  = "\n".join(sta_result["paths"][:15]) or "No path detail available"
        sta_section = f"""
━━━ OPENSTA TIMING REPORT (status: {sta_status}) ━━━

Worst Negative Slack (WNS): {sta_result['wns']:.3f} ns  (threshold: {STA_WNS_THRESHOLD} ns)
Total Negative Slack  (TNS): {sta_result['tns']:.3f} ns

VIOLATING PATHS:
{paths_txt}

"""

    return f"""I'm running a Verilator simulation (SystemVerilog) and it's FAILING.
Please analyze the errors and give me fixed versions of both files.

━━━ SIMULATION ERRORS (phase: {phase}) ━━━
{error_lines}

━━━ FULL OUTPUT ━━━
{full_output}
{yosys_section}{sta_section}
━━━ {rtl_name} (RTL Design) ━━━
```systemverilog
{rtl_code}
```

━━━ {tb_name} (Testbench) ━━━
```systemverilog
{tb_code}
```
{RTL_CONSTRAINTS}
━━━ WHAT I NEED ━━━
1. Tell me what is wrong (brief analysis)
2. Give me the COMPLETE fixed {rtl_name}
3. Give me the COMPLETE fixed {tb_name}
4. The fix should make "TEST PASSED" appear with 0 errors
{'5. Also fix ALL Yosys blocking issues listed above' if yosys_result and not yosys_result['clean'] else ''}
{'6. Reduce critical path depth to resolve timing violations (WNS > 0)' if sta_result and not sta_result['clean'] else ''}

Notes:
- Bugs may be in the RTL, the TB, or both — check carefully
- Do not change module port names or interfaces
- Return complete files, not diffs
- Use the Apply button to directly overwrite the files
"""


def build_yosys_only_prompt(rtl_code: str, tb_code: str, yosys_result: dict,
                              rtl_file: str, tb_file: str) -> str:
    rtl_name     = Path(rtl_file).name
    tb_name      = Path(tb_file).name
    blocking_txt = "\n".join(yosys_result["blocking"][:15])
    warnings_txt = "\n".join(yosys_result["warnings"][:10]) or "None"
    stats_txt    = "\n".join(yosys_result["stats"])         or "Not available"

    return f"""My Verilator simulation is PASSING ✅, but Yosys pre-synthesis found blocking issues
that must be fixed before this design can go to layout.

IMPORTANT: Do NOT change any functional behavior. The sim passes — preserve that.
Only fix the synthesis/structural issues listed below.

━━━ YOSYS PRE-SYNTHESIS ISSUES (BLOCKING) ━━━
{blocking_txt}

━━━ YOSYS WARNINGS ━━━
{warnings_txt}

━━━ DESIGN STATS ━━━
{stats_txt}

━━━ {rtl_name} (RTL Design) ━━━
```systemverilog
{rtl_code}
```

━━━ {tb_name} (Testbench — for context only, do not change) ━━━
```systemverilog
{tb_code}
```
{RTL_CONSTRAINTS}
━━━ WHAT I NEED ━━━
1. Brief explanation of each Yosys issue and its root cause
2. COMPLETE fixed {rtl_name} — synthesis-clean, functionally identical
3. {tb_name} — return unchanged (simulation already passes)
4. The fix must eliminate all BLOCKING issues above

Notes:
- Functional behavior must be preserved (sim already passes)
- No port/interface changes
- Return complete files, not diffs
- Use the Apply button to overwrite
"""


def build_sta_only_prompt(rtl_code: str, tb_code: str,
                           sta_result: dict, yosys_result: dict | None,
                           clock_period_ns: float,
                           rtl_file: str, tb_file: str) -> str:
    rtl_name  = Path(rtl_file).name
    tb_name   = Path(tb_file).name
    paths_txt = "\n".join(sta_result["paths"][:15]) or "No path details available"
    stats_txt = "\n".join(yosys_result["stats"]) if yosys_result else "Not available"

    return f"""My Verilator simulation is PASSING ✅ and Yosys synthesis is CLEAN ✅,
but OpenSTA found TIMING VIOLATIONS that must be fixed before layout.

IMPORTANT: Do NOT change functional behavior or port interfaces.
Only restructure RTL logic to reduce critical path depth and improve timing slack.

━━━ TIMING VIOLATIONS ━━━
Target Clock Period : {clock_period_ns:.3f} ns  ({1000/clock_period_ns:.0f} MHz)
Worst Negative Slack (WNS) : {sta_result['wns']:.3f} ns  (must be >= {STA_WNS_THRESHOLD} ns)
Total Negative Slack  (TNS) : {sta_result['tns']:.3f} ns

CRITICAL PATHS:
{paths_txt}

━━━ GATE-LEVEL STATS (from Yosys) ━━━
{stats_txt}

━━━ {rtl_name} (RTL Design) ━━━
```systemverilog
{rtl_code}
```

━━━ {tb_name} (Testbench — for context only, do not change) ━━━
```systemverilog
{tb_code}
```
{RTL_CONSTRAINTS}
━━━ WHAT I NEED ━━━
1. Identify which RTL constructs are causing the long critical paths
2. COMPLETE restructured {rtl_name} — timing-clean, functionally identical
3. {tb_name} — return unchanged
4. WNS must be >= {STA_WNS_THRESHOLD} ns after your fix

Timing improvement techniques to consider:
- Pipeline long combinational cones (insert registers)
- Break wide mux trees into balanced trees
- Reduce logic depth on data paths
- Retiming (shift registers toward outputs)
- Replace behavioral operators with timing-friendly structural RTL

Notes:
- Functional behavior must be preserved (sim already passes)
- No port/interface changes — latency changes are acceptable if documented
- Return complete files, not diffs
- Use the Apply button to overwrite
"""

# ─── FILE WATCHER ────────────────────────────────────────────────────────────

def build_watch_list(rtl_file: str, tb_file: str) -> list[str]:
    watch = []
    cwd   = Path.cwd()
    for f in [rtl_file, tb_file]:
        p = Path(f).resolve()
        watch.append(str(p))
        cwd_copy = cwd / p.name
        if str(cwd_copy.resolve()) != str(p):
            watch.append(str(cwd_copy))
    seen, unique = set(), []
    for w in watch:
        if w not in seen:
            seen.add(w)
            unique.append(w)
    return unique


def wait_for_any_file_update(rtl_file: str, tb_file: str,
                              timeout: int = 300, poll: float = 0.5) -> str | None:
    watch_list = build_watch_list(rtl_file, tb_file)
    mtimes = {}
    for f in watch_list:
        p = Path(f)
        mtimes[f] = p.stat().st_mtime if p.exists() else 0

    log("WATCH", f"Watching for Cognix Apply... (timeout: {timeout}s)", C.YELLOW)
    for f in watch_list:
        if Path(f).exists():
            log("WATCH", f"Watching: {f}", C.YELLOW)
        else:
            log("WATCH", f"Will watch if created: {f}", C.YELLOW)

    print(f"\n  {C.BOLD}➡  Paste prompt in Cognix → Enter → click ✅ Apply{C.RESET}\n")

    rtl_path = Path(rtl_file).resolve()
    tb_path  = Path(tb_file).resolve()
    name_to_canonical = {
        rtl_path.name: str(rtl_path),
        tb_path.name:  str(tb_path),
    }

    start = time.time()
    while time.time() - start < timeout:
        for f in watch_list:
            p = Path(f)
            try:
                new_mtime = p.stat().st_mtime if p.exists() else 0
            except Exception:
                new_mtime = 0
            if new_mtime > mtimes[f]:
                log("WATCH", f"Change detected in: {p.name} ✓", C.GREEN)
                time.sleep(1.5)
                canonical = name_to_canonical.get(p.name)
                if canonical and str(p.resolve()) != canonical:
                    shutil.copy(str(p), canonical)
                    log("SYNC", f"Copied {p.name} → test/ folder", C.CYAN)
                return f
        time.sleep(poll)

    log("WATCH", "Timeout — no file change detected.", C.RED)
    return None

# ─── BACKUP ──────────────────────────────────────────────────────────────────

def backup(rtl_file: str, tb_file: str, iteration: int):
    backup_dir = Path(f"ai_fix_backups/iter_{iteration:02d}")
    backup_dir.mkdir(parents=True, exist_ok=True)
    shutil.copy(rtl_file, backup_dir / Path(rtl_file).name)
    shutil.copy(tb_file,  backup_dir / Path(tb_file).name)
    log("BACKUP", f"Saved originals → {backup_dir}/", C.YELLOW)

# ─── RUN LOG ─────────────────────────────────────────────────────────────────

def save_run_log(rtl_file: str, tb_file: str, top: str,
                 sim_result: dict, yosys_result: dict | None,
                 sta_result: dict | None,
                 total_iterations: int, run_ts: str,
                 clock_period_ns: float):
    """
    Saves a complete archive of the passing run to run_logs/<timestamp>/:
      summary.json           structured pass report (JSON)
      verilator_output.txt   raw Verilator stdout+stderr
      yosys_output.txt       raw Yosys output (if ran)
      sta_output.txt         raw OpenSTA output (if ran)
      <design>.vcd           waveform (if TB uses $dumpfile)
      <rtl>.sv / <tb>.sv     final passing sources
    """
    log_root = Path("run_logs") / run_ts
    log_root.mkdir(parents=True, exist_ok=True)

    summary = {
        "run_id":           run_ts,
        "top_module":       top,
        "rtl_file":         Path(rtl_file).name,
        "tb_file":          Path(tb_file).name,
        "total_iterations": total_iterations,
        "final_status":     "PASSED",
        "clock_period_ns":  clock_period_ns,
        "verilator": {
            "phase":  sim_result.get("phase"),
            "passed": sim_result.get("passed"),
            "errors": sim_result.get("errors", []),
        },
        "yosys": {
            "ran":      yosys_result is not None,
            "clean":    yosys_result["clean"]    if yosys_result else None,
            "blocking": yosys_result["blocking"] if yosys_result else [],
            "warnings": yosys_result["warnings"] if yosys_result else [],
            "stats":    yosys_result["stats"]    if yosys_result else [],
        },
        "opensta": {
            "ran":           sta_result is not None,
            "clean":         sta_result["clean"] if sta_result else None,
            "wns_ns":        sta_result["wns"]   if sta_result else None,
            "tns_ns":        sta_result["tns"]   if sta_result else None,
            "wns_threshold": STA_WNS_THRESHOLD,
        },
        "timestamp": datetime.now().isoformat(),
    }

    (log_root / "summary.json").write_text(json.dumps(summary, indent=2))
    (log_root / "verilator_output.txt").write_text(sim_result.get("output", ""))

    if yosys_result is not None:
        (log_root / "yosys_output.txt").write_text(yosys_result.get("raw", ""))

    if sta_result is not None:
        (log_root / "sta_output.txt").write_text(sta_result.get("raw", ""))

    # Copy waveform if available (obj_dir/ or cwd)
    vcd_candidates = []
    if Path("obj_dir").exists():
        vcd_candidates += list(Path("obj_dir").glob("*.vcd"))
    vcd_candidates += list(Path(".").glob("*.vcd"))
    if vcd_candidates:
        latest_vcd = max(vcd_candidates, key=lambda p: p.stat().st_mtime)
        shutil.copy(str(latest_vcd), log_root / latest_vcd.name)

    for src in [rtl_file, tb_file]:
        shutil.copy(src, log_root / Path(src).name)

    banner(f"RUN LOG SAVED → run_logs/{run_ts}/", C.GREEN)
    for f in sorted(log_root.iterdir()):
        size     = f.stat().st_size
        size_str = f"{size:,} B" if size < 1_048_576 else f"{size/1_048_576:.1f} MB"
        print(f"    {C.CYAN}→ {f.name:<38} {size_str}{C.RESET}")
    print()

# ─── MAIN LOOP ───────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(
        description="RTL Auto-Fix — Verilator + Yosys + OpenSTA + Cognix"
    )
    parser.add_argument("--top",
        default=None,
        help="Top module name for simulation (auto-detected from TB if not set)")
    parser.add_argument("--max",
        default=5, type=int,
        help="Maximum Cognix fix iterations (default: 5)")
    parser.add_argument("--timeout",
        default=300, type=int,
        help="Seconds to wait for Cognix Apply per iteration (default: 300)")
    parser.add_argument("--clock-period",
        default=5.0, type=float,
        help="Target clock period in ns for OpenSTA timing analysis (default: 5.0 = 200 MHz)")
    parser.add_argument("--clock-port",
        default=None,
        help="RTL clock port name (auto-detected via heuristic if not set)")
    parser.add_argument("--liberty",
        default=None,
        help="Path to Liberty .lib file for OpenSTA (overrides env LIBERTY_PATH and auto-download)")
    parser.add_argument("--skip-yosys",
        action="store_true",
        help="Disable Yosys pre-synthesis stage")
    parser.add_argument("--skip-sta",
        action="store_true",
        help="Disable OpenSTA timing analysis stage")
    args = parser.parse_args()

    if not shutil.which("verilator"):
        log("ERROR", "verilator not found.", C.RED)
        log("ERROR", "Install: brew install verilator  |  apt install verilator", C.YELLOW)
        sys.exit(1)

    run_ts = datetime.now().strftime("%Y%m%d_%H%M%S")

    rtl_file, tb_file = detect_sv_files()

    if args.top is None:
        args.top = detect_top_module(tb_file)

    rtl_top    = detect_rtl_module(rtl_file)
    clock_port = args.clock_port or detect_clock_port(rtl_file)

    # ── Tool availability checks ─────────────────────────────────────────────
    yosys_available = (not args.skip_yosys) and bool(shutil.which("yosys"))
    if args.skip_yosys:
        log("YOSYS", "Skipped (--skip-yosys flag set)", C.YELLOW)
    elif not yosys_available:
        log("YOSYS", "Not found — skipping. brew install yosys  |  apt install yosys", C.YELLOW)

    sta_bin_found = _find_sta_binary() is not None
    liberty_path  = ensure_liberty_file(args.liberty) if (sta_bin_found and not args.skip_sta) else None
    sta_available = (not args.skip_sta) and sta_bin_found and (liberty_path is not None)

    if args.skip_sta:
        log("STA", "Skipped (--skip-sta flag set)", C.YELLOW)
    elif not sta_bin_found:
        log("STA", "OpenSTA not found — skipping.", C.YELLOW)
        log("STA", "Build: https://github.com/parallaxsw/OpenSTA  |  brew install opensta", C.YELLOW)
    elif liberty_path is None:
        log("STA", "Liberty file unavailable — skipping STA.", C.YELLOW)
        log("STA", "Tip: export LIBERTY_PATH=/path/to/your.lib  OR  use --liberty flag", C.YELLOW)

    # ── Startup banner ───────────────────────────────────────────────────────
    banner("🤖  RTL AUTO-FIX  ×  COGNIX  +  YOSYS  +  OpenSTA  🤖")
    print(f"  RTL          : {Path(rtl_file).name}")
    print(f"  Testbench    : {Path(tb_file).name}")
    print(f"  Top (sim)    : {args.top}")
    print(f"  RTL module   : {rtl_top}")
    print(f"  Clock port   : {clock_port or '(none — virtual clock)'}")
    print(f"  Clock period : {args.clock_period:.2f} ns  ({1000/args.clock_period:.0f} MHz target)")
    print(f"  WNS threshold: {STA_WNS_THRESHOLD} ns")
    print(f"  Max iters    : {args.max}")
    print(f"  Timeout      : {args.timeout}s")
    print(f"  Yosys        : {'enabled ✓' if yosys_available else 'disabled'}")
    print(f"  OpenSTA      : {'enabled ✓  [' + (_find_sta_binary() or '') + ']' if sta_available else 'disabled'}")
    if sta_available:
        print(f"  Liberty      : {liberty_path}")
    print()

    # ── Main iteration loop ──────────────────────────────────────────────────
    for iteration in range(1, args.max + 1):
        banner(f"ITERATION {iteration} / {args.max}", C.BLUE)

        # ── Stage 1: Verilator simulation ────────────────────────────────────
        sim_result = run_simulation(rtl_file, tb_file, args.top)

        if sim_result["passed"]:
            yosys_result = None
            sta_result   = None

            # ── Stage 2: Yosys pre-synthesis ─────────────────────────────────
            if yosys_available:
                yosys_result = run_yosys_checks(rtl_file, rtl_top)

                if yosys_result is not None and not yosys_result["clean"]:
                    banner("⚠️   SIM PASSED — YOSYS BLOCKING ISSUES FOUND", C.YELLOW)
                    backup(rtl_file, tb_file, iteration)
                    rtl_code = Path(rtl_file).read_text()
                    tb_code  = Path(tb_file).read_text()
                    prompt   = build_yosys_only_prompt(
                        rtl_code, tb_code, yosys_result,
                        rtl_file=rtl_file, tb_file=tb_file
                    )
                    if copy_to_clipboard(prompt):
                        print(f"{C.GREEN}  ✓ Yosys-fix prompt copied to clipboard!{C.RESET}\n")
                    else:
                        print(prompt)
                    open_cognix_chat()
                    changed = wait_for_any_file_update(rtl_file, tb_file, timeout=args.timeout)
                    if changed is None:
                        log("ERROR", "No file change detected within timeout.", C.RED)
                        sys.exit(1)
                    log("AUTO", "Re-running full check suite...", C.GREEN)
                    print()
                    continue

                # ── Stage 3: OpenSTA timing analysis ─────────────────────────
                if sta_available and yosys_result is not None:
                    netlist_path = yosys_result.get("netlist_path")

                    if netlist_path is None:
                        log("STA", "Netlist not written — skipping STA this iteration.", C.YELLOW)
                    else:
                        sta_result = run_opensta(
                            netlist_path    = netlist_path,
                            rtl_top         = rtl_top,
                            liberty_path    = liberty_path,
                            clock_port      = clock_port,
                            clock_period_ns = args.clock_period,
                        )

                        if sta_result is not None and not sta_result["clean"]:
                            banner("⚠️   YOSYS CLEAN — TIMING VIOLATIONS FOUND", C.YELLOW)
                            print(
                                f"  {C.YELLOW}WNS: {sta_result['wns']:.3f} ns  "
                                f"TNS: {sta_result['tns']:.3f} ns  "
                                f"(threshold: {STA_WNS_THRESHOLD} ns){C.RESET}\n"
                            )
                            backup(rtl_file, tb_file, iteration)
                            rtl_code = Path(rtl_file).read_text()
                            tb_code  = Path(tb_file).read_text()
                            prompt   = build_sta_only_prompt(
                                rtl_code, tb_code, sta_result,
                                yosys_result    = yosys_result,
                                clock_period_ns = args.clock_period,
                                rtl_file        = rtl_file,
                                tb_file         = tb_file,
                            )
                            if copy_to_clipboard(prompt):
                                print(f"{C.GREEN}  ✓ Timing-fix prompt copied to clipboard!{C.RESET}\n")
                            else:
                                print(prompt)
                            open_cognix_chat()
                            changed = wait_for_any_file_update(rtl_file, tb_file, timeout=args.timeout)
                            if changed is None:
                                log("ERROR", "No file change detected within timeout.", C.RED)
                                sys.exit(1)
                            log("AUTO", "Re-running full check suite...", C.GREEN)
                            print()
                            continue

            # ── All stages clean → save and exit ─────────────────────────────
            banner("✅  ALL CHECKS PASSED! SIM + SYNTHESIS + TIMING CLEAN.", C.GREEN)
            if iteration > 1:
                print(f"{C.GREEN}  Fixed in {iteration - 1} AI-assisted iteration(s) 🎉{C.RESET}\n")
            save_run_log(
                rtl_file, tb_file, args.top,
                sim_result       = sim_result,
                yosys_result     = yosys_result,
                sta_result       = sta_result,
                total_iterations = iteration,
                run_ts           = run_ts,
                clock_period_ns  = args.clock_period,
            )
            sys.exit(0)

        # ── Sim failed: enrich prompt with Yosys (skip STA — no point timing broken RTL)
        yosys_result = None
        sta_result   = None
        if yosys_available:
            yosys_result = run_yosys_checks(rtl_file, rtl_top)

        if iteration == args.max:
            banner("❌  MAX ITERATIONS REACHED", C.RED)
            sys.exit(1)

        backup(rtl_file, tb_file, iteration)

        rtl_code = Path(rtl_file).read_text()
        tb_code  = Path(tb_file).read_text()
        prompt   = build_cognix_prompt(
            rtl_code, tb_code, sim_result, iteration,
            rtl_file=rtl_file, tb_file=tb_file,
            yosys_result=yosys_result,
            sta_result=sta_result,
        )

        banner("📋  PROMPT READY — PASTE INTO COGNIX", C.CYAN)

        if copy_to_clipboard(prompt):
            print(f"{C.GREEN}  ✓ Prompt copied to clipboard!{C.RESET}\n")
        else:
            print(f"{C.YELLOW}  Could not auto-copy. Here is your prompt:\n{C.RESET}")
            print(prompt)

        open_cognix_chat()

        changed = wait_for_any_file_update(rtl_file, tb_file, timeout=args.timeout)
        if changed is None:
            log("ERROR", "No file change detected within timeout.", C.RED)
            sys.exit(1)

        log("AUTO", "Re-running simulation automatically...", C.GREEN)
        print()


if __name__ == "__main__":
    main()
