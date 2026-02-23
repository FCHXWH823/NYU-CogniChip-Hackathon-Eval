#!/usr/bin/env bash
# =============================================================================
# install_opensta.sh — Build and install OpenSTA from source
#
# OpenSTA: https://github.com/The-OpenROAD-Project/OpenSTA
# Source:  https://github.com/parallaxsw/OpenSTA  (upstream / canonical)
#
# Tested on Ubuntu 22.04 and macOS 14.
# Run with:  bash install_opensta.sh
# =============================================================================

set -euo pipefail

REPO_URL="https://github.com/parallaxsw/OpenSTA.git"
CUDD_URL="https://github.com/davidkebo/cudd/blob/main/cudd_versions/cudd-3.0.0.tar.gz?raw=true"
INSTALL_DIR="${OPENSTA_INSTALL_DIR:-/usr/local}"
BUILD_JOBS="${MAKE_JOBS:-$(nproc 2>/dev/null || sysctl -n hw.logicalcpu 2>/dev/null || echo 4)}"
WORKDIR="$(mktemp -d /tmp/opensta_build_XXXXXX)"

# ── Colors ────────────────────────────────────────────────────────────────────
RED='\033[91m'; GREEN='\033[92m'; YELLOW='\033[93m'
CYAN='\033[96m'; BOLD='\033[1m'; RESET='\033[0m'

info()  { echo -e "${CYAN}${BOLD}[INFO]${RESET}  $*"; }
ok()    { echo -e "${GREEN}${BOLD}[OK]${RESET}    $*"; }
warn()  { echo -e "${YELLOW}${BOLD}[WARN]${RESET}  $*"; }
die()   { echo -e "${RED}${BOLD}[ERROR]${RESET} $*" >&2; exit 1; }

echo ""
echo -e "${BOLD}════════════════════════════════════════════════════════════════${RESET}"
echo -e "${BOLD}  OpenSTA Build & Install Script${RESET}"
echo -e "${BOLD}  Install dir : ${INSTALL_DIR}${RESET}"
echo -e "${BOLD}  Build jobs  : ${BUILD_JOBS}${RESET}"
echo -e "${BOLD}  Work dir    : ${WORKDIR}${RESET}"
echo -e "${BOLD}════════════════════════════════════════════════════════════════${RESET}"
echo ""

# ── Detect OS ─────────────────────────────────────────────────────────────────
OS="$(uname -s)"
info "Detected OS: ${OS}"

# ── Check required system tools ───────────────────────────────────────────────
for tool in git cmake make curl tar; do
    command -v "$tool" &>/dev/null || die "'$tool' not found. Install it and re-run."
done

# ── Install system dependencies ───────────────────────────────────────────────
info "Installing system dependencies..."

if [[ "$OS" == "Darwin" ]]; then
    # macOS — use Homebrew
    command -v brew &>/dev/null || die "Homebrew not found. Install from https://brew.sh"
    brew bundle install --file=- <<'EOF'
brew "cmake"
brew "tcl-tk"
brew "swig"
brew "bison"
brew "flex"
brew "eigen"
EOF
    # Ensure Homebrew bison/flex take precedence over Apple's ancient versions
    export PATH="$(brew --prefix bison)/bin:$(brew --prefix flex)/bin:${PATH}"
    export CMAKE_INCLUDE_PATH="$(brew --prefix flex)/include"
    export CMAKE_LIBRARY_PATH="$(brew --prefix flex)/lib:$(brew --prefix bison)/lib"
    ok "macOS dependencies installed."

elif [[ "$OS" == "Linux" ]]; then
    # Linux — use apt (Debian/Ubuntu)
    command -v apt-get &>/dev/null || warn "apt-get not found — skipping system package install. Install manually."
    if command -v apt-get &>/dev/null; then
        sudo apt-get update -qq
        sudo apt-get install -y --no-install-recommends \
            build-essential cmake \
            tcl-dev \
            swig \
            bison \
            flex \
            libeigen3-dev \
            libz-dev \
            curl
        ok "Linux (apt) dependencies installed."
    fi
else
    warn "Unknown OS '${OS}' — skipping automatic dependency install."
fi

# ── Build and install CUDD (Binary Decision Diagram library, required) ────────
info "Building CUDD 3.0.0..."
cd "${WORKDIR}"
curl -fsSL --max-time 60 -o cudd-3.0.0.tar.gz "${CUDD_URL}"
tar xzf cudd-3.0.0.tar.gz
cd cudd-3.0.0
./configure --prefix="${WORKDIR}/cudd_install"
make -j"${BUILD_JOBS}"
make install
CUDD_DIR="${WORKDIR}/cudd_install"
ok "CUDD built → ${CUDD_DIR}"

# ── Clone OpenSTA ─────────────────────────────────────────────────────────────
info "Cloning OpenSTA from ${REPO_URL}..."
cd "${WORKDIR}"
git clone --depth=1 "${REPO_URL}" OpenSTA
cd OpenSTA

# ── Configure ─────────────────────────────────────────────────────────────────
info "Configuring with CMake (install → ${INSTALL_DIR})..."
mkdir build && cd build
cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
    -DCUDD_DIR="${CUDD_DIR}"

# ── Build ─────────────────────────────────────────────────────────────────────
info "Building with ${BUILD_JOBS} parallel jobs..."
make -j"${BUILD_JOBS}"

# ── Install ───────────────────────────────────────────────────────────────────
info "Installing to ${INSTALL_DIR} (may prompt for sudo)..."
if [[ -w "${INSTALL_DIR}" ]]; then
    make install
else
    sudo make install
fi

# ── Verify ────────────────────────────────────────────────────────────────────
if command -v sta &>/dev/null; then
    STA_VER="$(sta -version 2>&1 | head -1 || echo '(version check failed)')"
    ok "OpenSTA installed successfully!"
    ok "Binary: $(command -v sta)"
    ok "Version: ${STA_VER}"
else
    warn "'sta' not found on PATH after install."
    warn "Add ${INSTALL_DIR}/bin to your PATH:"
    warn "  export PATH=\"${INSTALL_DIR}/bin:\$PATH\""
fi

# ── Liberty file hint ─────────────────────────────────────────────────────────
echo ""
echo -e "${CYAN}${BOLD}Liberty file tip:${RESET}"
echo "  The auto_fix_cognix.py script auto-downloads NanGate45 on first run."
echo "  To use your own Liberty file:"
echo "    export LIBERTY_PATH=/path/to/your_library.lib"
echo "  OR pass it directly:"
echo "    python3 auto_fix_cognix.py --liberty /path/to/your_library.lib"
echo ""

# ── Cleanup ───────────────────────────────────────────────────────────────────
info "Cleaning up build directory: ${WORKDIR}"
rm -rf "${WORKDIR}"

echo ""
ok "Done! You can now run: python3 auto_fix_cognix.py"
echo ""
