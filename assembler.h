#ifndef __ASSEMBLER_HEADER__
#define __ASSEMBLER_HEADER__

// Data structure to store 2D array for symbol table
// I don't know what size to actually make this :p
typedef struct symbolTable{
    char symbols[32][2];
} SymbolTable;

typedef struct outputBuffer{
	char buffer[32]
} Buffer;

// Data structure to store 
typdef struct instructionSet{
	char instructions[8][2] = { "000",  "JMP"
								"100",	"LRP"			
								"010", 	"LDN"
								"110",	"STO"
								"001",	"SUB"
								"101",	"SUB"
								"011",	"CMP"
								"111",	"STP"}
}


#endif