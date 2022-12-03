#ifndef __COMPONENTS_HEADER__
#define __COMPONENTS_HEADER__

//#include <stdio.h>
#include <stdint.h>
#define STORE_SIZE 32

typedef uint32_t line;

typedef struct store{
    line lines[STORE_SIZE]; 
} Store;

typedef struct accumulator{
    line ARegister;
} Accumulator;

typedef struct control{
    line CInstruction;
    line PInstruction;
} Control;



#endif