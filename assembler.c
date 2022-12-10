/**
 * Lowrie Mouat
 * Matthew Gibson
 * Rachel Duncan
 * Robert Kelly
 * Tim Baxter
 * Zihan Tang
*/
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

void displaySymbolTable(SymbolTable *table){
	for(int i=0;i<SYMBOL_TABLE_SIZE;i++){
		if(strcmp(table->symbols[i], "")==0){
			printf("end of symbol table.\n");
			break;
		} else {
			printf("%s at address %d\n", table->symbols[i], table->address[i]);
		}
	}
}

void displaybuffer(Buffer *buffer){
	int consecutiveBlanks = 0;
	for(int i=0;i<BUFFER_SIZE;i++){
		printf("%s\n", buffer->buffer[i]);
		/*if(strcmp(buffer->buffer[i], "")==0){
			consecutiveBlanks++;
			if(consecutiveBlanks==3){
				printf("end of output buffer.\n");
				break;
			}
		} else {
			consecutiveBlanks=0;
			printf("%s\n", buffer->buffer[i]);
		}*/
	}
}

void decToBin(char token[], char binary[]){
    int num = atoi(token);
    int toAdd;
    int i =0;
    //translate to big-endian binary
    while (num>0){
    	toAdd=num%2;
    	if(toAdd){
    		binary[i]='1';
    	} else {
    		binary[i]='0';
    	}
    	num=num/2;
    	i++;
    }

    //fill remaining spaces
    for(int j=(strlen(binary));j<13;j++){
    	binary[j]='0';
    }
}

// Carries out the first pass in the analysis phase of the assembler
bool firstPass(Buffer *buffer, SymbolTable *table, const char *filename){
	// Open file to read
	FILE *fp = fopen(filename, "r");
	// Define instruction set (I was running out of time :/)
	char instructionBin[8][4]={"000","100","010","110","001","101","011","111"};
	char instructionName[8][4]={"JMP","LRP","LDN","STO","SUB","SUB","CMP","STP"};
	// Check file opened correctly
	if (fp!=NULL){
		// define instruction set
        int y = 0;
        char line[128];
        int currentAddress = 0;
        // Loop through file indicated by filename
        while(fgets(line, 128, fp)){
        	//if(line[0]==';') currentAddress--; // re-adjust address count if entire line is a comment
        	char * token = strtok(line, " "); // get first token
        	while(token!=NULL){ // loop to get all tokens
        		if(token[0]==';'){
        			// Skips the rest of a line upon hitting a comment
	        		break;
        		} else if (token[strlen(token)-1]==':'){ // check if token is a label
        			//printf("Label identified\n");
        			for(int i=0;i<32;i++){ // Loop through symboltable
        				if(strcmp(table->symbols[i], token)==0){ // check if label is in current symbol table spot
        					printf("label found in SymbolTable\n");
        					table->address[i]=currentAddress;
        					break;
        				} else if (strcmp(table->symbols[i], "")==0){
        					// Add symbol with address if found to not be presesnt.
        					printf("label not found in SymbolTable\n");
        					strcpy(table->symbols[i], token);
        					table->address[i]=currentAddress;
        					break;
        				}
        			}
        		} else if (strcmp(token, "VAR")==0){ // check if token is a command to store a variable
        			token = strtok(NULL, " "); // Get next token in order to get variable value
        			//NOTE: could add check to ensure there is a value?
        			char binary[14]={"\0"};
        			decToBin(token, binary);
        			printf("binary = %s\n", binary);
        			strcpy(buffer->buffer[currentAddress], binary);
        			currentAddress++;
        		} else {
        			for(int j=0;j<8;j++){ // loop through instruction set
        				if(strcmp(token, instructionName[j])==0){
        					printf(" - %s", instructionBin[j]);
        					strcpy(buffer->buffer[currentAddress], instructionBin[j]);
        					currentAddress++;
        					if(strcmp(token, "STP")==1){ //if not the stop command
        						token = strtok(NULL, " ");
        						// Look for lable in symbol table
	        					for(int i=0;i<32;i++){ // Loop through symboltable
			        				if(strcmp(table->symbols[i], token)==0){ // check if label is in current symbol table spot
			        					printf("label found in SymbolTable\n");
			        					if(SymbolTable->address[i]!=NULL){ // check variable is assigned
			        						
			        					}
			        				}
	        					}
        					}
        				}
        			}
        		}
        		printf(" %s\n", token); // print token
        		token = strtok(NULL, " ");
        	}

        	//EXTENSION check syntax of line & instructions are valid
        	//convert commands & numbers to machine code and send them to output buffer
        	//if unrecognized variable, leave 2 lines blank in output buffer
			//store any variables in symbol table
        }
    displaySymbolTable(table);
    displaybuffer(buffer);
    return true;
    }
}

// Carries out the second pass in the analysis phase of the assembler
/*bool secondPass(Buffer *buffer, SymbolTable *SymbolTable, char *filename){
	//loop through file indicated by filename 
		//check if previously unknown variable is now known
		//if so fill in gap in input buffer
		//else return false & print error message about reference to undeclaired variable
		return true;
}*/

// Carries out the synthesis phase of the assembler and writes the output a file.
/*void writeToFile(Buffer *buffer){
	// Open file to write to (currently hard coded to output.txt)
	FILE *fp = fopen("output.txt", "w");
	// Loop through input buffer until the end or next line is blank
	for(int i=0;i<BUFFER_SIZE;i++){
		char line[32]; //= (synthesise line);
		if(fp!=NULL){
	        //writeRow(fp, line);
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
		if(!(table==NULL && buffer==NULL)){
			// Checks that no errors occurend during memory allocation
			firstPass(buffer, table, filename);
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