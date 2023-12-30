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

    Byte operator[]( u32 Address ) const {
        
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

    Byte FetchByte( u32& Cycles, Mem& memory ) {
        Byte Data = memory[PC];
        PC++;
        Cycles--;

        return Data;
    }
};
