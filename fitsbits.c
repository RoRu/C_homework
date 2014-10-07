#include <stdio.h>

int isfits(int x, int wlen) {
    return !((x >> (wlen - 1)) + (!!(x >> (wlen - 1))));
}

int main(void) {
    int num, len;
    printf("%s", "Enter a number and length of word: \n");
    scanf("%d %d", &num, &len);
    printf("%d", isfits(num, len));
    return 0;
}
