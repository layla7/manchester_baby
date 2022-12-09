#ifndef __ASSEMBLER_HEADER__
#define __ASSEMBLER_HEADER__

// I don't know what size to actually make this :p
#define SYMBOL_TABLE_SIZE 32
// needs to be bigger as operands and commands are stored accross seperate lines
#define BUFFER_SIZE 64

// Data structure to store 2D array for symbol table
typedef struct symbolTable{
    char symbols[SYMBOL_TABLE_SIZE][2];
} SymbolTable;


typedef struct outputBuffer{
	char buffer[BUFFER_SIZE];
} Buffer;

// Data structure to store 
typedef struct instructionSet{
	char instructions[8][2]; 
} InstructionSet;

/*char instructons[2][8] = { "000",  "JMP",
					"100",	"LRP",
					"010", 	"LDN",
					"110",	"STO",
					"001",	"SUB",
					"101",	"SUB",
					"011",	"CMP",
					"111",	"STP"};*/

void assemble();
bool firstPass(Buffer *buffer, SymbolTable *SymbolTable, const char *filename);
bool secondPass(Buffer *buffer, SymbolTable *SymbolTable, const char *filename);
bool writeToFile(Buffer *buffer);

#endif