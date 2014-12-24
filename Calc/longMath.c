#include <stdio.h>
#include "longMath.h"
#include "listFunc.h"

#define DIV_BY_ZERO 1


void longn_input(longNum *result) {
    result->digits = NULL;
    result->sign = 0;
    result->numSize = 0;
    char sym = ' ';
    sinList temp = NULL;

    while(1) {
        sym = getchar();
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
    int dec = 0;

    if(left.sign == right.sign) {
        res->sign = left.sign;
        while((left.digits != NULL) && (right.digits != NULL)) {
            sl_addElm(&(res->digits), (left.digits->data + right.digits->data + dec) % 10);
            res->numSize++;
            dec = (left.digits->data + right.digits->data + dec) / 10;
            left.digits = left.digits->nextElm;
            right.digits = right.digits->nextElm;
        }

        if(left.numSize > right.numSize) {
            int i = 0;
            for(i; i < left.numSize - right.numSize; i++) {
                sl_addElm(&(res->digits), (left.digits->data + dec) % 10);
                res->numSize++;
                dec = (left.digits->data + dec) / 10;
                left.digits = left.digits->nextElm;
            }
        }
        else if(left.numSize < right.numSize) {
            int i = 0;
            for(i; i < right.numSize - left.numSize; i++) {
                sl_addElm(&(res->digits), (right.digits->data + dec) % 10);
                res->numSize++;
                dec = (right.digits->data + dec) / 10;
                right.digits = right.digits->nextElm;
            }
        }
        if(dec == 1) {
            sl_addElm(&(res->digits), 1);
            res->numSize++;
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
            res->numSize++;
        }
    }

    sinList revNum = NULL;
    sl_reverse(&revNum, res->digits);
    sl_delList(&(res->digits));
    res->digits = revNum;
    longn_delZero(res);
}

void longn_subtr(longNum *res, longNum major, longNum minor) {
    while((major.digits != NULL) && (minor.digits != NULL)) {

        if(major.digits->data >= minor.digits->data) {
            sl_addElm(&(res->digits), major.digits->data - minor.digits->data);
            res->numSize++;
        }
        else {
            sl_addElm(&(res->digits), (major.digits->data + 10) - minor.digits->data);
            res->numSize++;
            major.digits->nextElm->data--;
        }

        major.digits = major.digits->nextElm;
        minor.digits = minor.digits->nextElm;
    }

    if(major.numSize > minor.numSize) {
        int i = 0;
        for(i; i < major.numSize - minor.numSize; i++) {
            sl_addElm(&(res->digits), major.digits->data);
            res->numSize++;
            major.digits = major.digits->nextElm;
        }
    }
}

void longn_mult(longNum *res, longNum left, longNum right) {
    sinList head = left.digits;

    if((left.digits->data == 0) || (right.digits->data == 0)) {
        sl_addElm(&(res->digits), 0);
        return;
    }

    if(left.sign + right.sign == 0) {
        res->sign = 0;
    }
    else {
        res->sign = -1;
    }

    int i = 0;
    for(i; i < (left.numSize + right.numSize); i++) {
        sl_addElm(&(res->digits), 0);
        res->numSize++;
    }

    sinList tempHead = res->digits;
    sinList tempHeadIns = res->digits;
    int div = 0;
    while(right.digits != NULL) {
        while(left.digits != NULL) {
            tempHeadIns->data += (right.digits->data * left.digits->data + div) % 10;
            div = tempHeadIns->data / 10;
            tempHeadIns->data %= 10;

            tempHeadIns = tempHeadIns->nextElm;
            left.digits = left.digits->nextElm;
        }
        if(div != 0) {
            tempHeadIns->nextElm->data = div;
        }

        div = 0;
        tempHead = tempHead->nextElm;
        tempHeadIns = tempHead;
        right.digits = right.digits->nextElm;
        left.digits = head;
    }
    longn_delZero(res);
}

void longn_div(longNum *res, longNum num, longNum den) {
    if(den.digits->data == 0) {
        printf("Division by zero");
        exit(DIV_BY_ZERO);
    }

    if(longn_lessNum(num, den) == 1) {
        sl_addElm(&(res->digits), 0);
        return;
    }

    if(num.digits->data == 0) {
        sl_addElm(&(res->digits), 0);
        return;
    }

    if(num.sign - den.sign == 0) {
        res->sign = 0;
    }
    else {
        res->sign = -1;
    }

    longNum tnum = {0};
    sl_reverse(&(tnum.digits), num.digits);
    sinList head = tnum.digits;

    longNum d = {0};
    int i = 0;
    for(i; i < den.numSize; i++) {
        sl_addElm(&(d.digits), tnum.digits->data);
        d.numSize++;
        tnum.digits = tnum.digits->nextElm;
    }

    sinList mod = tnum.digits;
    sl_revPrint(mod);
    int count = 0;
    int origSign = den.sign;
    den.sign = -1;

    while(1) {

        if(longn_lessNum(d, den) == 1) {
            sl_addElm(&(res->digits), count);
            sl_addElm(&(d.digits), mod->data);
            d.numSize++;
            mod = mod->nextElm;
            count = 0;
        }

        longNum sub1 = {0};
        longNum sub2 = {0};
        longn_sum(&sub1, den, d);

        count++;
        sl_delList(&(d.digits));
        d.digits = sub1.digits;
        d.numSize = sub1.numSize;

        if((longn_lessNum(d, den) == 1) && (mod == NULL)) {
            sl_addElm(&(res->digits), count);
            break;
        }
    }

    if((num.sign == -1) && (d.digits->data != 0)) {
        res->digits->data++;
    }

}


void longn_delZero(longNum *target) {
    if(target->digits->data != 0) {
        sinList temp = NULL;
        sl_reverse(&temp, target->digits);
        while(temp->data == 0) {
            sl_delElm(&temp, 0);
            temp == temp->nextElm;
            target->numSize--;
        }
        sl_delList(&(target->digits));
        sl_reverse(&(target->digits), temp);
    }
}


void longn_showNum(longNum target) {
    if(target.digits == NULL) {
        return;
    }
    if(target.sign == 0) {
        sl_revPrint(target.digits);
    }
    else {
        printf("-");
        sl_revPrint(target.digits);
    }
}
