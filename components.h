#ifndef __COMPONENTS_HEADER__'
#define __COMPONENTS_HEADER__

//#include <stdio.h>
#include <stdint.h>
#define STORE_SIZE 32

typedef struct store{
    char lines[STORE_SIZE][32]; 
} Store;

typedef struct accumulator{
    char ARegister[32];
} Accumulator;

typedef struct control{
    char CInstruction[32];
    char PInstruction[32];
} Control;



#endif