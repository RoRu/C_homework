#ifndef LISTFUNC_H
#define LISTFUNC_H

struct li {
        int data;
    struct li* nextElm;
};

typedef struct li* sinList;

void addElm(sinList *sl, int x);

void delElm(sinList *sl, int x);

void printList(sinList sl);

void delList(sinList *sl);

#endif