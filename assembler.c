#include <stdio.h>  // required for access to file input-output functions in C
#include <stdlib.h> // required for access to memory allocation functions
#include <string.h> // required for validation on filename entry
#include "assembler.h"

// Gets the user to input the filename for the file to be assembled
char[] getAssemblyFile(){
    char filename[]; // initiallise variable to store filename
    printf("Enter name of file to assemble: ");
    scanf("%s", filename);
    bool exists = false;
    if (access(filename, F_OK) == 0) {
    	// checks if a file with user inputed name exists, as seen here https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c
		exists = true;
		return filename;
	} else {
		printf("No file with name %s exists, aborting assembly proccess", filename);
		return NULL;
	}   
}

firstPass(Buffer *buffer, SymbolTable *SymbolTable, char[] filename){
	
}

// Carries out the assemly process
void assemble(){
	char[] filename = getAssemblyFile();
	if(!strcmp(filename, NULL)){
		// Checks filename isn't null, only occurs if no file matched entered filename
		//initialise syboltable and output buffer
		SymbolTable *table = (SymbolTable*)malloc(sizeof(SymbolTable));
		Buffer *buffer = (Buffer*)malloc(sizeof(Buffer));
		if(!(adjMatrixPtr==NULL || buffer==NULL)){
			// Checks that no errors occurend during memory allocation
			firstPass(*buffer, *SymbolTable, filename);
			secondPass();
        	
    	} else {
    		printf("Error occured durring memory allocation, aborting assembly proccess.")
        	break
    	}
	} else {
		break;
	}
}