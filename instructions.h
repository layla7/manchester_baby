#ifndef __INSTRUCTIONS_HEADER__
#define __INSTRUCTIONS_HEADER__

//#include "components.h"

/**
 * @param CI pointer to the contents of the control instruction
 * @param storeline the store location line
 * 
 * Set the Control Instruction to the contents of the Store Line
*/
void jmp(Control *control, Store *store, int storeline);

/**
 * @param CI pointer to the contents of the control instruction
 * @param storeline the store location line
 * 
 * Add the content of the store line to the control instruction
*/
void jrp(Control *control, Store *store, int storeline);

/**
 * @param accumulator pointer to the contents of the accumulator
 * @param storeline the store location line
 * 
 * Load accumulator to negative form of store content
*/
void ldn(Accumulator *accumulator, Store *store, int storeline);

/**
 * @param accumulator the contents of the accumulator
 * @param storeline pointer to the store location line
 * 
 * Copy contents of the accumulator to the store location
*/
void sto(Accumulator *accumulator, Store *store, int storeline);

/**
 * @param accumulator pointer to the contents of the accumulato
 * @param storeline pointer to the store location line
 * 
 * Subtract content of the store location from accumulator
*/
void sub(Accumulator *accumulator, Store *store, int storeline);

/**
 * @param accumulator pointer to the contents of the accumulato
 * @param CI pointer to the contents of the control instruction
 * 
 * Increment CI if Accumulator value negative otherwise do nothing
*/
void comp(Control *control, Accumulator *accumulator);

/**
 * halt machine
*/
void stp();
#endif