#ifndef __ASSEMBLER_HEADER__
#define __ASSEMBLER_HEADER__

// I don't know what size to actually make this :p
#define SYMBOL_TABLE_SIZE 32
// needs to be bigger as operands and commands are stored accross seperate lines
#define BUFFER_SIZE 64

// Data structure to store 2D array for symbol table
typedef struct symbolTable{
    char symbols[SYMBOL_TABLE_SIZE][30];
    int address[SYMBOL_TABLE_SIZE];
} SymbolTable;


typedef struct outputBuffer{
	char buffer[BUFFER_SIZE][32];
} Buffer;

void assemble();
bool firstPass(Buffer *buffer, SymbolTable *SymbolTable, const char *filename);
bool secondPass(Buffer *buffer, SymbolTable *SymbolTable, const char *filename);
bool writeToFile(Buffer *buffer);

#endif