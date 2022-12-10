#include "components.h"
#include "instructions.h"
#include "operations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void jmp(Control *control, Store *store, int storeline){
    for (int i = 0; i < BITS; i++){
        control -> CInstruction[i] = store -> lines[storeline][i];
    }
}

void jrp(Control *control, Store *store, int storeline){
    bool carry = false;
    char total[BITS]; 
    for (int i = 0; i < BITS; i++){
            if (carry == true){
                if(control->CInstruction[i] == '1' && store->lines[storeline][i] == '1'){
                    carry=true;
                    total[i] = '0';
                }
                else if(control->CInstruction[i] == '1' || total[i] == '1'){
                    carry = true;
                    total[i] = '0';
                }
                else{
                    total[i] = '1';
                    carry = false;
                }
            }
            else{
                if(control -> CInstruction[i] == '1' && store->lines[storeline][i] == '1'){
                    carry = true;
                    total[i] = '0';
                }
                else if(control -> CInstruction[i] == '0' && store->lines[storeline][i] == '0'){
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
    }  
}

void ldn(Accumulator *accumulator, Store *store, int storeline){
    for (int i = 0; i < BITS-1; i++){
        accumulator -> ARegister[i] = store -> lines[storeline][i];
    }

    if(store -> lines[storeline][BITS - 1] == '0'){
        accumulator -> ARegister[BITS - 1] = '1';
    }
    else accumulator -> ARegister[BITS - 1] = '0';
}

void sto(Accumulator *accumulator, Store *store, int storeline){
    for (int i = 0; i < BITS - 1; i++){
        store -> lines[storeline][i] = accumulator -> ARegister[i];
    }
}

void sub(Accumulator *accumulator, Store *store, int storeline){
    bool carry = false;
    char total[BITS]; 
    for (int i = 0; i < BITS - 1; i++){
        if (carry == true){
                if(accumulator->ARegister[i] == '1' && store->lines[storeline][i] == '1'){
                    carry=true;
                    total[i] = '0';
                }
                else if(accumulator->ARegister[i] == '1' || store->lines[storeline][i] == '1'){
                    carry = true;
                    total[i] = '0';
                }
                else{
                    total[i] = '1';
                    carry = false;
                }
            }
        else{
            if(accumulator->ARegister[i] == '1' && store->lines[storeline][i] == '1'){
                carry = true;
                total[i] = '0';
            }
            else if(accumulator->ARegister[i] == '0' && store->lines[storeline][i] == '0'){
                carry = false;
                total[i] = '0';
            }
            else{
                total[i] = '1';
            }
        }
        if((i == BITS - 1) && carry == true) printf("Binary addition out of range");
    }

    total[BITS - 1] = '1';
    for(int i = 0; i < BITS; i++){
        accumulator -> ARegister[i] = total[i];
    } 
}

void comp(Control *control, Accumulator *accumulator){
    if(accumulator -> ARegister[BITS - 1] == '1'){
        incrementCI(control);
    }
}

void stp(){
    exit(0);
    //insert call to menu function here
}
