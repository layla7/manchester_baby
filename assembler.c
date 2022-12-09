#include <stdio.h>  // required for access to file input-output functions in C
#include <stdlib.h> // required for access to memory allocation functions
#include <string.h> // required for validation on filename entry
#include <unistd.h> // required to check if filename entered is blank
#include <stdbool.h> // required for boolean stuff
#include <string.h> // required for string stuff
#include "assembler.h"

// Gets the user to input the filename for the file to be assembled
bool getAssemblyFile(char filename[]){
    printf("Enter name of file to assemble: ");
    scanf("%s", filename);
    if (access(filename, F_OK) == 0) {
    	// checks if a file with user inputed name exists, as seen here https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c
		return true;
	} else {
		printf("No file with name %s exists, aborting assembly proccess \n", filename);
		return false;
	}   
}

// Carries out the first pass in the analysis phase of the assembler
/*bool firstPass(Buffer *buffer, SymbolTable *SymbolTable, const char *filename){
	// Open file to read
	FILE *fp = fopen("output.txt", "r");
	// Check file opened correctly
	if (fp!=NULL){
		// define instruction set
        int y = 0;
        char line[128];
        int currentAddress = 0;
        // Loop through file indicated by filename
        for(int i=0;fgets(line, 128, fp) != NULL;i++){
        	if(line[0]=";"){
        		// Skips iteration if the line is just a comment
        		continue;
        	}
        	char * token = strtok(string, " "); // get first token
        	while(token!=NULL){ // loop to get all tokens
        		printf(" %s\n", token) // print token
        		token = strtok(NULL," ");
        	}
        	//EXTENSION check syntax of line & instructions are valid
        	//convert commands & numbers to machine code and send them to output buffer
        	//if unrecognized variable, leave 2 lines blank in output buffer
			//store any variables in symbol table
			currentAddress++;
		return true;
        }
    }	
}*/

// Carries out the second pass in the analysis phase of the assembler
/*bool secondPass(Buffer *buffer, SymbolTable *SymbolTable, char[] filename){
	//loop through file indicated by filename 
		//check if previously unknown variable is now known
		//if so fill in gap in input buffer
		//else return false & print error message about reference to undeclaired variable
		//return true
}*/

// Carries out the synthesis phase of the assembler and writes the output a file.
/*void writeToFile(Buffer *buffer){
	// Open file to write to (currently hard coded to output.txt)
	FILE *fp = fopen("output.txt", "w");
	// Loop through input buffer until the end or next line is blank
	for(int i=0;i<BUFFER_SIZE;i++){
		//line = (synthesise line);
		if(fp!=NULL){
	        writeRow(fp, line);
	    }
	}
	fclose(fp);
}*/

// Carries out the assemly process
void assemble(){
    char filename[30] = {'\0'};
	if (getAssemblyFile(filename)){
		// Checks filename isn't empty, only occurs if no file matched entered filename
		//initialise syboltable and output buffer
		SymbolTable *table = NULL;
		Buffer *buffer = NULL;
		table = (SymbolTable*)malloc(sizeof(SymbolTable));
		buffer = (Buffer*)malloc(sizeof(Buffer));
		if(!(table==NULL || buffer==NULL)){
			// Checks that no errors occurend during memory allocation
			firstPass(*buffer, *SymbolTable, filename);
			//secondPass(*buffer, *SymbolTable, filename);
        	//writeToFile(*buffer);
    	} else {
    		printf("Error occured durring memory allocation, aborting assembly proccess.\n");
        	return;
    	}
	}
}

int main()
{
	assemble();
}