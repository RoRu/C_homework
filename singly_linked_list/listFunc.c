/*
Simple implementation of singly linked list with some basic functions.
Functional file.
Author: Yumatov Vladimir, group 171
*/

#include <stdio.h>
#include "listFunc.h"

void addElm(sinList *sl, int x) {
    if(*sl == NULL) {
        *sl = (sinList)malloc(sizeof(struct li));
        (*sl)->data = x;
        (*sl)->nextElm = NULL;
    }
    else {
        sinList temp = (sinList)malloc(sizeof(struct li));
        temp->data = x;
        temp->nextElm = *sl;
        *sl = temp;
    }
}

void delElm(sinList *sl, int x) {
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
        }
        sinList doomed = (*sl)->nextElm;
        (*sl)->nextElm = (*sl)->nextElm->nextElm;
        free(doomed);
        *sl = head;
    }
}

void printList(sinList sl) {
    if(sl == NULL) {
        printf("There is nothing in this list\n");
    }
    else {
        while(sl != NULL) {
            printf("%d ", sl->data);
            sl = sl->nextElm;
        }
        printf("\n");
    }
}

void delList(sinList *sl) {
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