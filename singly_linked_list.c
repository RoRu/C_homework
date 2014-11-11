/*
Simple implementation of singly linked list with some basic functions
Author: Yumatov Vladimir, group 171
*/
#include <stdio.h>

struct li {
    int data;
    struct li* nextElm;
};

typedef struct li* sinList;

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

int main(void) {
    sinList myList = NULL;
    char command = ' ';
    int num = 0;
    while(1) {
        scanf("%c", &command);
        switch(command) {
            case 'a': {
                scanf("%d", &num);
                addElm(&myList, num);
                break;
            }
            case 'r': {
                scanf("%d", &num);
                delElm(&myList, num);
                break;
            }
            case 'p': {
                printList(myList);
                break;
            }
            case 'q': {
                delList(&myList);
                return 0;
            }
        }
    }
    return 0;
}
