#include <6502.hpp>

int main() {
    Mem mem;
    CPU cpu;

    cpu.Reset( mem );
    printf("got ya!! \n");

    return 0;
}