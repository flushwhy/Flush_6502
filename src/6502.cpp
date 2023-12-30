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
      
      switch ( Ins ){
        case INS_LDA_IM:
        {
          Byte Value = FetchByte( Cycles, memory );
          A = Value;
          Z = (A == 0);
          N = (A & 0b10000000) > 0;
        } break;
        default:
        {
          printf("Instruction not handled %d ", Ins);
        } break;
      }
    }
}

void Mem::Initialise() {

    for ( u32 i = 0; i < MAX_MEM; i++ ) {
        Data[i] = 0;
    }
}
