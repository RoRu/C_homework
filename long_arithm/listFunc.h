#ifndef LISTFUNC_H
#define LISTFUNC_H

struct li {
    int data;
    struct li* nextElm;
};

typedef struct li* sinList;

void sl_addElm(sinList *, int);

void sl_delElm(sinList *, int);

void sl_reverse(sinList *, sinList);

void sl_print(sinList);

void sl_delList(sinList *);

#endif
