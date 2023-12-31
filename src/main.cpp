#include <6502.hpp>

int main() {
    Mem mem;
    CPU cpu;

    cpu.Reset( mem );
    mem[0xFFFC] = CPU::INS_LDA_ZP;
    mem[0xFFFD] = 0x42;
    mem[0x0042] = 0x61;
    cpu.Execute(2, mem );
    return 0;
}