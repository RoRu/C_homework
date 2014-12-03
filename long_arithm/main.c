/*
Long arithmetic with + and -
Author: Yumatov Vladimir, group 171
*/

#include <stdio.h>
#include "listFunc.h"
#include "longMath.h"

int main(void) {
    longNum batman = {0};
    longNum robin = {0};
    longNum joker = {0};
    longn_input(&batman);
    longn_input(&robin);
    longn_sum(&joker, batman, robin);
    longn_showNum(joker);

    return 0;
}
