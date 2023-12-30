#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

stuct Mem {
    constexpr MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM]
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

    void Reset();

};
