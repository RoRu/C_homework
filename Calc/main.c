/*
Simple implementation of singly linked list with some basic functions
Author: Yumatov Vladimir, group 171
*/

#include <stdio.h>
#include "listFunc.h"
#include "longMath.h"
#include "myStack.h"

#define UNKNOWN_COMMAND 1
#define IGNORE_CHAR 2
#define ARG_ERR 1


int calc_input(longNum *result) {

    char sym = ' ';
    sinList temp = NULL;

    while(1) {
        sym = getchar();
        if(sym == '-') {
            sym = getchar();
            if((sym >= 48) && (sym <= 57)) {
                !!(result->sign) ? (result->sign = 0) : (result->sign = -1);
                sl_addElm(&temp, (int)(sym - '0'));
                result->numSize++;
            }
            else {
                return '-';
            }
        }
        else if((sym >= '0') && (sym <= '9')) {
            sl_addElm(&temp, (int)(sym - '0'));
            result->numSize++;
        }
        else if(sym == '\n') {
            break;
        }
        else if((sym == '+') || (sym == '-') || (sym == '*') || (sym == '/') || (sym == '=') || (sym == 'q')) {
            return sym;
        }
        else {
            printf("Unknown command");
            exit(UNKNOWN_COMMAND);
        }
    }
    if(temp == NULL) {
        return IGNORE_CHAR;
    }
    result->digits = temp;
    return 1;
}


void calc_argCheck(myStack st) {
    if((st == NULL) || (st->nextElm == NULL)) {
        printf("Not enough arguments");
        exit(ARG_ERR);
    }
}


int main(void) {
    myStack stck = {0};
    int stopFlag = 0;
    stack_initElm(&stck);
    longNum result = {0};
    while(1) {
        stopFlag = calc_input(&(stck->n));
        //printf("Flag is %d\n", stopFlag);
        //longn_showNum(stck->n);
        if(stopFlag == 'q') {
            stack_delElm(&stck);
            break;
        }
        else if(stopFlag == 1) {
            stack_initElm(&stck);
            continue;
        }
        else if(stopFlag == '=') {
            longn_showNum(stck->nextElm->n);
            printf("\n");
        }
        else if(stopFlag == '+') {
            stack_delElm(&stck);
            calc_argCheck(stck);

            longn_sum(&result, stck->n, stck->nextElm->n);
            stack_delElm(&stck);

            stck->n = result;
            stck->n.numSize = result.numSize;
            stck->n.sign = result.sign;

            result.digits = NULL;
            result.numSize = 0;
            result.sign = 0;

            stack_initElm(&stck);
        }
        else if(stopFlag == '-') {
            stack_delElm(&stck);
            calc_argCheck(stck);

            !!(stck->nextElm->n.sign) ? (stck->nextElm->n.sign = 0) : (stck->nextElm->n.sign = -1);
            longn_sum(&result, stck->n, stck->nextElm->n);
            stack_delElm(&stck);

            stck->n = result;
            stck->n.numSize = result.numSize;
            stck->n.sign = result.sign;

            result.digits = NULL;
            result.numSize = 0;
            result.sign = 0;
            stack_initElm(&stck);
        }
        else if(stopFlag == '*') {
            stack_delElm(&stck);
            calc_argCheck(stck);

            longn_mult(&result, stck->n, stck->nextElm->n);
            stack_delElm(&stck);

            stck->n = result;
            stck->n.numSize = result.numSize;
            stck->n.sign = result.sign;

            result.digits = NULL;
            result.numSize = 0;
            result.sign = 0;

            stack_initElm(&stck);
        }
        else if(stopFlag == '/') {
            stack_delElm(&stck);
            calc_argCheck(stck);

            longn_div(&result, stck->n, stck->nextElm->n);
            stack_delElm(&stck);

            stck->n = result;
            stck->n.numSize = result.numSize;
            stck->n.sign = result.sign;

            result.digits = NULL;
            result.numSize = 0;
            result.sign = 0;

            stack_initElm(&stck);
    }
}

    printf("[");
    while(stck->nextElm != NULL) {
        longn_showNum(stck->n);
        printf("; ");
        stack_delElm(&stck);
    }
    longn_showNum(stck->n);
    stack_delElm(&stck);
    printf("]");

    return 0;
}
