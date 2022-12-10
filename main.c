/**
 * Lowrie Mouat
 * Matthew Gibson
 * Rachel Duncan
 * Robert Kelly
 * Tim Baxter
 * Zihan Tang
*/
#include "components.h"
#include "operations.h"
#include "instructions.h"
#include <stdbool.h>
#include <stdlib.h>

int main(){
    Store* store = (Store*)malloc(sizeof(Store));
    Accumulator* accumulator = (Accumulator*)malloc(sizeof(Accumulator));
    Control* control = (Control*)malloc(sizeof(Control));
    startup(store, accumulator, control);
    while(true){
        incrementCI(control);
        fetch(store, control);
        decodex(control, accumulator, store);
        display(store, accumulator, control);
    }
}