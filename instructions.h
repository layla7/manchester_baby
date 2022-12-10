#ifndef __INSTRUCTIONS_HEADER__
#define __INSTRUCTIONS_HEADER__

//#include "components.h"

/**
 * @param store a pointer to the store
 * @param accumulator a pointer to the accumulator
 * @param storeline an integer storing the line number of the store
 * 
 * Reads the machine code file to be used in the program into the store
*/
void jmp(Control *control, Store *store, int storeline);

/**
 * @param store a pointer to the store
 * @param control a pointer to a struct containing both the PInstruction and CInstruction registers
 * @param storeline an integer storing the line number of the store
 * 
 * adds the content of the store location to CI
*/
void jrp(Control *control, Store *store, int storeline);

/**
 * @param store a pointer to the store
 * @param accumulator a pointer to the accumulator
 * @param storeline an integer storing the line number of the store
 * 
 * Load accumulator to negative form of store content
*/
void ldn(Accumulator *accumulator, Store *store, int storeline);

/**
 * @param store a pointer to the store
 * @param accumulator a pointer to the accumulator
 * @param storeline an integer storing the line number of the store
 * 
 * Copy contents of the accumulator to the store location
*/
void sto(Accumulator *accumulator, Store *store, int storeline);

/**
 * @param store a pointer to the store
 * @param accumulator a pointer to the accumulator
 * @param storeline an integer storing the line number of the store
 * 
 * Subtract content of the store location from accumulator
*/
void sub(Accumulator *accumulator, Store *store, int storeline);

/**
 * @param control a pointer to a struct containing both the PInstruction and CInstruction registers
 * @param accumulator a pointer to the accumulator
 * 
 * Increment CI if Accumulator value negative otherwise do nothing
*/
void comp(Control *control, Accumulator *accumulator);

/**
 * halt machine
*/
void stp();
#endif