#include <6502.hpp>

int main() {
    Mem mem;
    CPU cpu;

    cpu.Reset( mem );
    mem[0xFFFC] = CPU::INS_jup;
    mem[0xFFFD] = 0x42;
    mem[0xFFFE] = 0x42;
    cpu.Execute(3, mem );
    return 0;
}