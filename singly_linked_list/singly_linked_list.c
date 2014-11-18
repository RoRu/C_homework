/*
Simple implementation of singly linked list with some basic functions.
Main file.
Author: Yumatov Vladimir, group 171
*/

#include <stdio.h>
#include "listFunc.h"

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
