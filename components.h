#ifndef __COMPONENTS_HEADER__
#define __COMPONENTS_HEADER__

//#include <stdio.h>
#include <stdint.h>
#define STORE_SIZE 32
#define BITS 32

typedef struct store{
    char lines[STORE_SIZE][BITS]; 
} Store;

typedef struct accumulator{
    char ARegister[BITS];
} Accumulator;

typedef struct control{
    char CInstruction[BITS];
    char PInstruction[BITS];
} Control;



#endif