#include "components.h"
#include "operations.h"
#include "instructions.h"
#include <stdbool.h>
#include <stdlib.h>


void startup(Store *store, Accumulator *accumulator, Control *control){
    for(int i = 0; i<STORE_SIZE; i++){
        for (int j = 0; j < BITS; j++)
        {
            store->lines[i][j] = '0';
        }
    }

    for (int j = 0; j < BITS; j++)
    {
        //accumulator->ARegister[j] = '0';
        //control->CInstruction[j] = '0';
        //control->PInstruction[j] = '0';
    }

    fileread(store);
}


void fileread(Store *store){
    FILE *fp;

    fp = fopen("BabyTest1-MC.txt","r");
    char temp;
    int storeline = 0;
    int i = 0;

    if(!fp){
        printf("Failure opening file, returning to menu...");
        exit(0);
        //call to menu here

    }

    while ((temp = fgetc(fp)) != EOF){
        if(temp == '\n'){
            storeline = storeline + 1;
            i = 0;
        }
        else{
            store->lines[storeline][i] = temp;
            i++;
        }
    }
    
}

/**
 * Addition for incrimenting CI not working currently. Would be good if someone smarter than me checked it out. 
 * Feels like I'm missing something obvious.
*/
void incrementCI(Control *control){
    char add1[BITS]; 
    for(int i = 0; i < BITS; i++){
        add1[i] =  '0';
    }
    add1[0] = '1';
    bool carry = false;
    char total[BITS];

    for (int i = 0; i < BITS; i++){
            if (carry == true){
                if(control->CInstruction[i] == '1' && add1[i] == '1'){
                    carry=true;
                    total[i] = '0';
                }
                else if(control->CInstruction[i] == '1' || add1[i] == '1'){
                    carry = true;
                    total[i] = '0';
                }
                else{
                    total[i] = '1';
                    carry = false;
                }
            }
            else{
                if(control -> CInstruction[i] == '1' && add1[i] == '1'){
                    carry = true;
                    total[i] = '0';
                }
                else if(control -> CInstruction[i] == '0' && add1[i] == '0'){
                    carry = false;
                    total[i] = '0';
                }
                else{
                    total[i] = '1';
                }
            }
            //if((i == BITS - 1) && carry == true) printf("Binary addition out of range");
    }

    for(int i = 0; i < BITS; i++){
        control -> CInstruction[i] = total[i];
        //printf("%c",control->CInstruction[i]);
    }
    printf("\n");
}

void fetch(Store *store, Control *control){
    int location = 0;
    int number = 1;
    for(int i = 0; i < 5; i++){
        if(control->CInstruction[i] == '1') location = location + number;
        number = number * 2;
    }

    for(int i = 0; i < BITS; i++){
        control->PInstruction[i] = store->lines[location][i]; 
    }
}

void decodex(Control *control, Accumulator *accumulator, Store *store){
    int lineNo = 0;
    int functionNo = 0;
    int number = 1;

    number = 1;
    for(int i = 13; i < 16; i++){
        if(control->PInstruction[i] == '1') functionNo = functionNo + number;
        number = number * 2;
    }

    if(functionNo != 7 || functionNo != 6){
        for(int i = 0; i < 5; i++){
            if(control->PInstruction[i] == '1') lineNo = lineNo + number;
            number = number * 2;
        }
    }
    //printf("%d",lineNo);
    switch(functionNo)
    {
        case 0:
            jmp(control, store, lineNo);
            break;

        case 1:
            jrp(control, store, lineNo);
            break;
        
        case 2:
            ldn(accumulator, store, lineNo);
            break;
            
        case 3:
            sto(accumulator, store, lineNo);
            break;

        case 4:
            sub(accumulator, store, lineNo);
            break;

        case 5:
            sub(accumulator, store, lineNo);
            break;

        case 6:
            comp(control, accumulator);
            break;

        case 7:
            stp();
            break;
    }
}

void display(Store* store, Accumulator* accumulator, Control* control){
    
    
    for(int i = 0; i < STORE_SIZE; i++){
        printf("%c", accumulator->ARegister[i]);
    }
    printf("\n");
}
