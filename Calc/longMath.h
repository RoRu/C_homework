#ifndef LONGMATH_H
#define LONGMATH_H

#include "listFunc.h"

typedef struct longNumber {
    int sign;
    int numSize;
    sinList digits;
} longNum;

int longn_lessNum(longNum, longNum);

void longn_sum(longNum *, longNum, longNum);

void longn_subtr(longNum *, longNum, longNum);

void longn_mult(longNum *, longNum, longNum);

void longn_div(longNum *, longNum, longNum);

void longn_delZero(longNum *);

void longn_showNum(longNum);

#endif
