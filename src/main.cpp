#include <6502.hpp>

int main() {
    Mem mem;
    CPU cpu;

    cpu.Reset( mem );
    cpu.Execute(2, mem );
    return 0;
}