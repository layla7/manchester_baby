#ifndef __OPERATIONS_HEADER__
#define __OPERATIONS_HEADER__
#include <stdio.h>

/**
 * @param store a pointer to the store
 * Reads the machine code file to be used in the program into the store
*/
void fileread(Store *store);

/**
 * @param store a pointer to the store
 * @param accumulator a pointer to the accumulator
 * @param control a pointer to a struct containing both the PInstruction and CInstruction registers
 * 
 * Reads the machine code file to be used in the program into the store
*/
void startup(Store *store, Accumulator *accumulator, Control *control);

/**
 * @param control a pointer to a struct containing both the PInstruction and CInstruction registers
 *
 * Incriments the CInstruction to move to the next line of the store
*/
void incrementCI(Control *control);

/**
 * @param store a pointer to the store
 * @param control a pointer to a struct containing both the PInstruction and CInstruction registers
 * 
 * fetches the instruction stored in the line of the store and stores it in PInstruction 
*/
void fetch(Store *store, Control *control);

/**
 * @param store a pointer to the store
 * @param accumulator a pointer to the accumulator
 * @param control a pointer to a struct containing both the PInstruction and CInstruction registers
 * 
 * converts the instruction and line number for PInstruction to integers and runs the accoring instruction
*/
void decodex(Control *control, Accumulator *accumulator, Store *store);
void display(Store *store, Accumulator *accumulator, Control *control);
#endif