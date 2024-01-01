#pragma once
#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct Mem {
    
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialise();
    void WriterWord( Word WordVal, u32 Address, u32& Cycles );

    Byte& operator[]( u32 Address ) {
        
        return Data[Address];
    }
};

struct CPU {

    Word PC;
    Word SP;

    Byte A, X, Y;

    Byte C : 1;
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1; 
    Byte N : 1;

    void Reset( Mem& memory );
    void Execute(u32 Cycles, Mem& memory );
    void LDASetStatus();
    
    static constexpr Byte 
    INS_LDA_IM  = 0xA9,
    INS_LDA_ZP  = 0xA5,
    INS_LDA_ZPX = 0xB5,
    INS_jup     = 0x20;
 

    Byte FetchByte( u32& Cycles, Mem& memory ) {
        Byte Data = memory[PC];
        PC++;
        Cycles--;

        return Data;
    }

    Byte ReadByte( u32& Cycles, Byte Address, Mem& memory ) {
        Byte Data = memory[Address];
        Cycles--;
        return Data;
    }

    Word FetchWord( u32& Cycles, Mem& memory ) {
        Word Data = memory[PC];
        PC++;

        Data |= ( memory[PC] << 8 );
        PC++;

        Cycles -= 2;

        return Data;
    }
};