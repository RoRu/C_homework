#include "stdio.h"
#include "listFunc.h"
#include "longMath.h"
#include "myStack.h"

#define NOT_ENOUGH_MEMORY 1


void stack_initElm(myStack *stck) {
    if(*stck == NULL) {

        *stck = (myStack)malloc(sizeof(struct st));
        if (*stck == 0) {
            printf("Not enough memory");
            exit(NOT_ENOUGH_MEMORY);
        }
        (*stck)->n.numSize = 0;
        (*stck)->n.digits = NULL;
        (*stck)->nextElm = NULL;
        (*stck)->n.sign = 0;
    }
    else {

        myStack temp = (myStack)malloc(sizeof(struct st));
        if (temp == 0) {
            printf("Not enough memory");
            exit(NOT_ENOUGH_MEMORY);
        }
        temp->n.numSize = 0;
        temp->n.digits = NULL;
        temp->n.sign = 0;
        temp->nextElm = *stck;
        *stck = temp;
    }
}

void stack_delElm(myStack *stck) {
    myStack doomed = *stck;
    sl_delList(&((*stck)->n.digits));
    *stck = (*stck)->nextElm;
    free(doomed);
}


