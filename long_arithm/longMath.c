/*
Functions for working with long numbers and long arithmetic.
Author: Yumatov Vladimir, group 171
*/

#include <stdio.h>
#include "longMath.h"
#include "listFunc.h"

void longn_input(longNum *result) {
    result->digits = NULL;
    result->sign = 0;
    result->numSize = 0;
    result->isCalculated = 0;
    char sym = ' ';
    sinList temp = NULL;

    while(1) {
        scanf("%c", &sym);
        if(sym == '-') {
            !!(result->sign) ? (result->sign = 0) : (result->sign = -1);
        }
        if((sym >= 48) && (sym <= 57)) {
            sl_addElm(&temp, (int)(sym - '0'));
            result->numSize++;
        }
        else if(sym == 'q') {
            break;
        }
    }
    result->digits = temp;
}



/*void longn_selfReverse(sinList *target) {
    if((*target)->nextElm == NULL) {
        return;
    }

    sinList head = *target;
    sinList helper = *target;
    int temp = 0;
    while(helper != NULL) {
        temp = helper->data;
        helper = helper->nextElm;
        sl_delElm(target, temp);
        sl_addElm(&head, temp);
        *target = (*target)->nextElm;
    }
    *target = head;
}*/

int longn_lessNum(longNum first, longNum second) {
    if(first.numSize > second.numSize) {
        return 2;
    }

    else if(first.numSize < second.numSize) {
        return 1;
    }

    else {
        sinList rev1 = NULL,
                rev2 = NULL;
        sl_reverse(&rev1, first.digits);
        sl_reverse(&rev2, second.digits);

        while((rev1->data == rev2->data) && (rev1->nextElm != NULL)) {
            rev1 = rev1->nextElm;
            rev2 = rev2->nextElm;
        }
        if(rev1->data < rev2->data) {
            sl_delList(&rev1);
            sl_delList(&rev2);
            return 1;
        }
        else if(rev1->data > rev2->data){
            sl_delList(&rev1);
            sl_delList(&rev2);
            return 2;
        }
        else {
            sl_delList(&rev1);
            sl_delList(&rev2);
            return 0;
        }
    }
}

void longn_sum(longNum *res, longNum left, longNum right) {
    res->isCalculated = 1;
    res->digits = NULL;
    int dec = 0;

    if(left.sign == right.sign) {
        res->sign = left.sign;
        while((left.digits != NULL) && (right.digits != NULL)) {
            sl_addElm(&(res->digits), (left.digits->data + right.digits->data + dec) % 10);
            dec = (left.digits->data + right.digits->data + dec) / 10;
            left.digits = left.digits->nextElm;
            right.digits = right.digits->nextElm;
        }

        if(left.numSize > right.numSize) {
            int i = 0;
            for(i; i < left.numSize - right.numSize; i++) {
                sl_addElm(&(res->digits), (left.digits->data + dec) % 10);
                dec = (left.digits->data + dec) / 10;
                left.digits = left.digits->nextElm;
            }
        }
        else if(left.numSize < right.numSize) {
            int i = 0;
            for(i; i < right.numSize - left.numSize; i++) {
                sl_addElm(&(res->digits), (right.digits->data + dec) % 10);
                dec = (right.digits->data + dec) / 10;
                right.digits = right.digits->nextElm;
            }
        }
        if(dec == 1) {
            sl_addElm(&(res->digits), 1);
        }
    }
    else {
        if(longn_lessNum(left, right) == 1) {
            longn_subtr(res, right, left);
            res->sign = right.sign;
        }
        else if(longn_lessNum(left, right) == 2) {
            longn_subtr(res, left, right);
            res->sign = left.sign;
        }
        else {
            sl_addElm(&(res->digits), 0);
        }
    }
}

void longn_subtr(longNum *res, longNum major, longNum minor) {
    res->digits = NULL;
    while((major.digits != NULL) && (minor.digits != NULL)) {

        if(major.digits->data >= minor.digits->data) {
            sl_addElm(&(res->digits), major.digits->data - minor.digits->data);
        }
        else {
            sl_addElm(&(res->digits), (major.digits->data + 10) - minor.digits->data);
            major.digits->nextElm->data--;
        }

        major.digits = major.digits->nextElm;
        minor.digits = minor.digits->nextElm;
    }

    if(major.numSize > minor.numSize) {
        int i = 0;
        for(i; i < major.numSize - minor.numSize; i++) {
            sl_addElm(&(res->digits), major.digits->data);
            major.digits = major.digits->nextElm;
        }
    }
}

void longn_showNum(longNum target) {
    sinList rev = NULL;
    if(target.isCalculated == 0) {
        if(target.sign == 0) {
            sl_reverse(&rev, target.digits);
            sl_print(rev);
        }
        else {
            sl_reverse(&rev, target.digits);
            printf("-");
            sl_print(rev);
        }
    }
    else {
        if(target.sign == 0) {
            sl_print(target.digits);
        }
        else {
            printf("-");
            sl_print(target.digits);
        }
    }
}
