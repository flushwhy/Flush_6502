#include "6502.hpp"

void CPU::Reset( Mem& memory) {
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


    memory.Initialise();
}

void CPU::Execute(u32 Cycles, Mem& memory ) {
    
    while( Cycles > 0 )
    {
        Byte Ins = FetchByte( Cycles, memory );
    }
}

void Mem::Initialise() {

    for ( u32 i = 0; i < MAX_MEM; i++ ) {
        Data[i] = 0;
    }
}