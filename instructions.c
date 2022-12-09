#include "components.h"
#include "instructions.h"
#include <stdbool.h>

void jmp(Control *control, Store *store, int storeline){
    for (int i = 0; i < BITS; i++){
        control -> CInstruction[i] = store -> lines[storeline][i];
    }
}

void jrp(Control *control, Store *store, int storeline){
    bool carry = false;
    char total[BITS]; 
    for (int i = 0; i < BITS - 1; i++){
        if (control -> CInstruction[i] == "1" && store -> lines[storeline][i] == "1"){
            carry = true;
            total[i] = "0";
        }
        else if((control -> CInstruction[i] == "1" && store -> lines[storeline][i] == "0") || (control -> CInstruction[i] == "0" && store -> lines[storeline][i] == "1")){
            if (carry = true){
                total[i] = "0";
            }
            else{
                total[i] = "1";
            }
        }
        else{
            total[i] = "0";
            carry = false;
        }
        if((i == BITS - 1) && carry == true) printf("Binary addition out of range");
    }

    for(int i = 0; i < BITS; i++){
        control -> CInstruction[i] = total[i];
    }  
}

void ldn(Accumulator *accumulator, Store *store, int storeline){
    for (int i = 0; i < BITS - 1; i++){
        accumulator -> ARegister[i] = store -> lines[storeline][i];
    }

    if(store -> lines[storeline][BITS - 1] == 0){
        accumulator -> ARegister[BITS - 1] == 1;
    }
    else accumulator -> ARegister[BITS - 1] == 0;
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
        if (accumulator -> ARegister[i] == "1" && store -> lines[storeline][i] == "1"){
            carry = true;
            total[i] = "0";
        }
        else if((accumulator -> ARegister[i] == "1" && store -> lines[storeline][i] == "0") || (accumulator -> ARegister[i] == "0" && store -> lines[storeline][i] == "1")){
            if (carry = true){
                total[i] = "0";
            }
            else{
                total[i] = "1";
            }
        }
        else{
            total[i] = "0";
            carry = false;
        }
        if((i == BITS - 1) && carry == true) printf("Binary addition out of range");
    }

    total[BITS - 1] = "1";
    for(int i = 0; i < BITS; i++){
        accumulator -> ARegister[i] = total[i];
    } 
}

void comp(Control *control, Accumulator *accumulator){
    char add1[BITS]; 
    for(int i = 0; i < BITS; i++){
        add1[i] =  "0";
    }
    add1[0] = "1";
    char total[BITS];
    bool carry = false;

    if(accumulator -> ARegister[BITS - 1] == "1"){
        for (int i = 0; i < BITS; i++){
            if (control -> CInstruction[i] == "1" && add1[i] == "1"){
                carry = true;
                total[i] = "0";
            }
            else if((control -> CInstruction[i] == "1" && add1[i] == "0") || (control -> CInstruction[i] == "0" && add1[i] == "1")){
                if (carry = true){
                    total[i] = "0";
                }
                else{
                    total[i] = "1";
                }
            }
            else{
                total[i] = "0";
                carry = false;
            }
            if((i == BITS - 1) && carry == true) printf("Binary addition out of range");
    }
    }
}

void stp(){
    //insert call to menu function here
}
