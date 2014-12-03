/*
Functions for work with singly linked list.
Author: Yumatov Vladimir, group 171
*/

#include <stdio.h>
#include "listFunc.h"

#define NOT_ENOUGH_MEMORY_RC 1

void sl_addElm(sinList *sl, int x) {
    if(*sl == NULL) {
        *sl = (sinList)malloc(sizeof(struct li));
        if (*sl == 0) {
            printf("Not enough memory");
            exit(NOT_ENOUGH_MEMORY_RC);
        }
        (*sl)->data = x;
        (*sl)->nextElm = NULL;
    }
    else {
        sinList temp = (sinList)malloc(sizeof(struct li));
        if (*sl == 0) {
            printf("Not enough memory");
            exit(NOT_ENOUGH_MEMORY_RC);
        }
        temp->data = x;
        temp->nextElm = *sl;
        *sl = temp;
    }
}

void sl_delElm(sinList *sl, int x) {
    if(*sl == NULL) {
        printf("Sorry, I cannot delete nothing :(\n");
    }
    if((*sl)->data == x) {
        sinList doomed = *sl;
        *sl = (*sl)->nextElm;
        free(doomed);
    }
    else {
        sinList head = *sl;
        while((*sl)->nextElm->data != x) {
            (*sl) = (*sl)->nextElm;
            if((*sl)->nextElm == NULL) {
                printf("There is no such number\n");
                *sl = head;
                return;
            }
        }
        sinList doomed = (*sl)->nextElm;
        (*sl)->nextElm = (*sl)->nextElm->nextElm;
        free(doomed);
        *sl = head;
    }
}

void sl_reverse(sinList *res, sinList target) {
    while(target != NULL) {
        sl_addElm(res, target->data);
        target = target->nextElm;
    }
}

void sl_print(sinList sl) {
    if(sl == NULL) {
        printf("There is nothing in this list\n");
    }
    else {
        while(sl != NULL) {
            printf("%d", sl->data);
            sl = sl->nextElm;
        }
        printf("\n");
    }
}

void sl_delList(sinList *sl) {
    if(*sl == NULL) {
        printf("Sorry, there is no list to delete :(\n");
    }
    else {
        sinList first = *sl;
        while((*sl) != NULL) {
            first = *sl;
            *sl = (*sl)->nextElm;
            free(first);
        }
    }
}
