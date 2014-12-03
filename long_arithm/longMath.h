#ifndef LONGMATH_H
#define LONGMATH_H

#include "listFunc.h"

typedef struct longNumber {
    int sign;
    int numSize;
    int isCalculated;
    sinList digits;
} longNum;

void longn_input(longNum *);

int longn_lessNum(longNum, longNum);

void longn_sum(longNum *, longNum, longNum);

void longn_subtr(longNum *, longNum, longNum);

void longn_showNum(longNum);

#endif
