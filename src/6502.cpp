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
          
          LDASetStatus();
        }break;
        case INS_LDA_ZP:
        {
          Byte ZeroPageAddress = FetchByte( Cycles, memory );
          A = ReadByte( Cycles, ZeroPageAddress, memory );

          LDASetStatus();
        }break;
        case INS_LDA_ZPX:
        {
          Byte ZeroPageAddress = FetchByte( Cycles, memory );
          ZeroPageAddress += X;
          Cycles--;
        }break;
        case INS_jup:
        {
          Word SubAddress = FetchWord ( Cycles, memory );
          memory.WriterWord( PC - 1, SP, Cycles );
          SP--;
          PC = SubAddress;
          Cycles--;
        }break;
        default:
        {
          printf("Instruction not handled %d ", Ins);
        }break;
      }
    }
}

void CPU::LDASetStatus() {
  Z = (A== 0);
  N = (A & 0b10000000 > 0);
}

/*END OF CPU FUNTCIONS*/

/* START OF MEMORY FUNCTCIONS*/
void Mem::Initialise() {

    for ( u32 i = 0; i < MAX_MEM; i++ ) {
        Data[i] = 0;
    }
}

void Mem::WriterWord( Word WordVal, u32 Address, u32& Cycles ) {
  Data[Address]   =   WordVal & 0xFF;
  Data[Address + 1] = (WordVal >> 8);
  Cycles -= 2;
}