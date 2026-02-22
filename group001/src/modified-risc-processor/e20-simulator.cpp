#include <cstddef>
#include <cstdint>  // explicitly include for uint8_t and uint16_t types
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

// Some helpful constant values that we'll be using.
uint16_t const static MEM_SIZE      = 1 << 13;
uint16_t const static NUM_REGS      = 8;
uint16_t const static NUM_REG_BITS  = 3;  // how many bits represent a reg ID
size_t const static REG_SIZE        = 1 << 16;
uint16_t const static MEM_DUMP_SIZE = 1 << 7;  // 128, as listed in the document

// Opcodes for different kinds of instructions

// MSBs that indicate a three register instruction
// Bit shift to get the 3 MSBs (instr >> 13)
uint16_t const static THREE_REG = 0b000;

// If THREE_REG
// If instructions have three registers, then we look at the last four bits
// Use bit-twiddling to get the last four digits (func)
uint16_t const static ADD = 0b0000;
uint16_t const static SUB = 0b0001;
uint16_t const static OR  = 0b0010;
uint16_t const static AND = 0b0011;
uint16_t const static SLT = 0b0100;
uint16_t const static JR  = 0b1000;

// Check to see if it's TWO_REG - first three digits
uint16_t const static ADDI = 0b001;
uint16_t const static LW   = 0b100;
uint16_t const static SW   = 0b101;
uint16_t const static JEQ  = 0b110;
uint16_t const static SLTI = 0b111;

// No reg:
uint16_t const static J   = 0b010;
uint16_t const static JAL = 0b011;

// Used for JAL:
uint16_t const static LINK_REGISTER = 7;

// Function prototypes
void load_machine_code(ifstream& f, uint16_t mem[]);
void simulate_machine_mode(uint16_t& currPC, uint16_t regs[], uint16_t mem[]);
void print_state(uint16_t pc, uint16_t regs[], uint16_t mem[],
                 size_t mem_quantity);

// Positions of the registers
// Left, middle, and right registers as shown in machine code
uint16_t const static LEFT_REG_POS  = 10;
uint16_t const static MID_REG_POS   = 7;
uint16_t const static RIGHT_REG_POS = 4;

/*
    Main function
    Takes command-line args as documented below
*/
int main(int argc, char* argv[])
{
    // Parse the command-line arguments
    char* filename  = nullptr;
    bool  do_help   = false;
    bool  arg_error = false;
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        if (arg.rfind("-", 0) == 0) {
            if (arg == "-h" || arg == "--help")
                do_help = true;
            else
                arg_error = true;
        } else {
            if (filename == nullptr)
                filename = argv[i];
            else
                arg_error = true;
        }
    }
    // Display error message if appropriate
    if (arg_error || do_help || filename == nullptr) {
        cerr << "usage " << argv[0] << " [-h] filename" << endl << endl;
        cerr << "Simulate E20 machine" << endl << endl;
        cerr << "positional arguments:" << endl;
        cerr << "  filename    The file containing machine code, typically "
                "with .bin suffix"
             << endl
             << endl;
        cerr << "optional arguments:" << endl;
        cerr << "  -h, --help  show this help message and exit" << endl;
        return 1;
    }

    ifstream f(filename);
    if (!f.is_open()) {
        cerr << "Can't open file " << filename << endl;
        return 1;
    }

    // Initialize program counter, registers, and memory (RAM)
    uint16_t currPC = 0;

    // Doing this doesn't completely make all the entries zero
    uint16_t ram[MEM_SIZE];
    uint16_t regs[NUM_REGS];

    // Clear garbage values in memory
    for (size_t i = 0; i < MEM_SIZE; i++) {
        ram[i] = 0;
    }

    // Clear garbage values in the registers
    for (size_t i = 0; i < NUM_REGS; i++) {
        regs[i] = 0;
    }

    // Load f and parse using load_machine_code
    load_machine_code(f, ram);

    // Do simulation.
    simulate_machine_mode(currPC, regs, ram);

    // Print the final state of the simulator before ending, using print_state()
    print_state(currPC, regs, ram, MEM_DUMP_SIZE);

    return 0;
}

/*
    Loads an E20 machine code file into the list provided by `mem`.
    We assume that `mem` is large enough to hold the values in the machine
    code file.

    @param f    Open file to read from
    @param mem  Array representing memory into which to read program
*/
void load_machine_code(ifstream& f, uint16_t mem[])
{
    regex    machine_code_re("^ram\\[(\\d+)\\] = 16'b(\\d+);.*$");
    uint16_t expectedaddr = 0;
    string   line;
    while (getline(f, line)) {
        smatch sm;
        if (!regex_match(line, sm, machine_code_re)) {
            cerr << "Can't parse line: " << line << endl;
            exit(1);
        }
        uint16_t addr  = stoi(sm[1], nullptr, 10);
        uint16_t instr = stoi(sm[2], nullptr, 2);
        if (addr != expectedaddr) {
            cerr << "Memory addresses encountered out of sequence: " << addr
                 << endl;
            exit(1);
        }
        if (addr >= MEM_SIZE) {
            cerr << "Program too big for memory" << endl;
            exit(1);
        }
        expectedaddr++;
        mem[addr] = instr;
    }
}

/*
    Modifies the value of the program counter, registers, and memory
    as it simulates the machine code that was loaded into memory, which is
    stored in the `mem` array

    @param currPC   The current value of the program counter
    @param regs     Register array storing values for all 8 registers
    @param mem      Memory array that was initialized with machine code
*/
void simulate_machine_mode(uint16_t& currPC, uint16_t regs[], uint16_t mem[])
{
    uint16_t prevPC;  // used to check for changes in the program counter
    while (true) {
        // Basically extract the first three bits, which is the opcode
        // Use the opcode to handle each case individually

        // Split three register arguments into more
        // the IDs for regA, regB, and regDst

        uint16_t currInstr = mem[currPC & (MEM_SIZE - 1)];
        prevPC             = currPC;
        currPC++;  // assume the program counter increments by 1 each time

        // Getting the registers as formatted in the machine code
        // ((1 << NUM_REG_BITS) - 1) always evaluates to 7 with E20 format
        uint16_t leftReg
            = (currInstr >> LEFT_REG_POS) & ((1 << NUM_REG_BITS) - 1);
        uint16_t midReg
            = (currInstr >> MID_REG_POS) & ((1 << NUM_REG_BITS) - 1);
        uint16_t rightReg
            = (currInstr >> RIGHT_REG_POS) & ((1 << NUM_REG_BITS) - 1);

        // 7th and 13th LSBs for imm7 and imm13, respectively
        uint16_t imm7  = currInstr & ((1 << 7) - 1);
        uint16_t imm13 = currInstr & ((1 << 13) - 1);

        // Sign-extend for imm7 if its 7th LSB (MSB) is a 1
        if ((imm7 & 0b0111'1111) >> 6) imm7 |= 0b1111'1111'1000'0000;

        // basically extract the first three bits
        // this is the opcode, base things from there
        switch (currInstr >> 13) {
            // Handle instructions with three register arguments first
            // as they have the same opcode
            case THREE_REG: {
                // For readability and referring to the manual
                uint16_t regSrcA = leftReg;
                uint16_t regSrcB = midReg;
                uint16_t regDst  = rightReg;

                uint16_t func = (currInstr & 0b1111);

                // If regDst is the $0, just do nothing
                if (!regDst && func != JR) break;

                // Extract the last four bits
                switch (func) {
                    case JR:  // only uses one register in the regSrcA position
                        currPC = regs[regSrcA];
                        break;
                    // The following cases look almost identical to what's found
                    // in the manual
                    case ADD:
                        regs[regDst] = regs[regSrcA] + regs[regSrcB];
                        break;
                    case SUB:
                        regs[regDst] = regs[regSrcA] - regs[regSrcB];
                        break;
                    case OR:
                        regs[regDst] = regs[regSrcA] | regs[regSrcB];
                        break;
                    case AND:
                        regs[regDst] = regs[regSrcA] & regs[regSrcB];
                        break;
                    case SLT:
                        // Unsigned comparison
                        regs[regDst] = (regs[regSrcA] < regs[regSrcB]) ? 1 : 0;
                        break;
                }
                break;
            }

            // Two register arguments
            case ADDI:
                // R[regDst] <- R[regSrc] + imm
                regs[midReg] = regs[leftReg] + imm7;
                break;
            case LW:
                // R[regDst] <- Mem[R[regAddr] + imm]
                regs[midReg] = mem[(regs[leftReg] + imm7) & (MEM_SIZE - 1)];
                break;
            case SW:
                // Mem[R[regAddr] + imm] <- R[regSrc]
                mem[(regs[leftReg] + imm7) & (MEM_SIZE - 1)] = regs[midReg];
                break;
            case JEQ:
                // pc <- (R[regA] == R[regB]) ? pc+1+rel_imm : pc+1
                // Just add the immediate value as the increment as done before
                if (regs[leftReg] == regs[midReg]) currPC = currPC + imm7;
                break;
            case SLTI:
                // Unsigned comparison
                // R[regDst] <- (R[regSrc] < imm) ? 1 : 0
                regs[midReg] = (regs[leftReg] < imm7) ? 1 : 0;
                break;

            // No register arguments
            // Could take advantage of fall through
            // first JAL, then J because they share the "currPC = imm13" line
            case J:
                // pc <- imm
                currPC = imm13;
                break;
            case JAL:
                // R[7] <- pc+1; pc <- imm
                // Note that currPC was already incremented before
                regs[LINK_REGISTER] = currPC;
                currPC              = imm13;
                break;
        }

        // Check for changes
        if (currPC == prevPC) break;
    }
}

/*
    Prints the current state of the simulator, including
    the current program counter, the current register values,
    and the first `mem_quantity` elements of memory.

    @param pc           The final value of the program counter
    @param regs         Final value of all registers
    @param memory       Final value of memory
    @param mem_quantity How many words of memory to dump
*/
void print_state(uint16_t pc, uint16_t regs[], uint16_t memory[],
                 size_t mem_quantity)
{
    cout << setfill(' ');
    cout << "Final state:" << endl;
    cout << dec << "\tpc=" << setw(5) << pc << endl;

    for (size_t reg = 0; reg < NUM_REGS; reg++)
        cout << "\t$" << reg << "=" << setw(5) << dec << regs[reg] << endl;

    cout << setfill('0');
    bool cr = false;
    for (size_t count = 0; count < mem_quantity; count++) {
        cout << hex << setw(4) << memory[count] << " ";
        cr = true;
        if (count % 8 == 7) {
            cout << endl;
            cr = false;
        }
    }
    if (cr) cout << endl;
}