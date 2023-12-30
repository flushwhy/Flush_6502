#include "6502.hpp"

void CPU::Reset() {
    PC = 0xFFFC;
    SP = 0x0100;
    A = 0;
    X = 0;
    Y = 0;
    C = 1;
    Z = 1;
    I = 1;
    D = 1;
    B = 1;
    V = 1;
    N = 1;
}