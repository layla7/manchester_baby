#ifndef __OPERATIONS_HEADER__
#define __OPERATIONS_HEADER__
#include <stdio.h>

void fileread(Store *store);
void startup(Store *store, Accumulator *accumulator, Control *control);
void incrementCI(Control *control);
void fetch(Store *store, Control *control);
void decodex(Control *control, Accumulator *accumulator, Store *store);
void display(Store *store);
#endif