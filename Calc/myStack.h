#ifndef MYSTACK_H
#define MYSTACK_H

#include "listFunc.h"
#include "longMath.h"

struct st {
    longNum n;
    struct st *nextElm;
};

typedef struct st *myStack;

void stack_initElm(myStack *);

void stack_delElm(myStack *);

#endif
