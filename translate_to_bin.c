#include <stdio.h>

int main(void) {
    int num;
    int bits = sizeof(num) * 8;

    printf("Enter the number: ");
    scanf("%d", &num);

    int i = 0;
    for (i = bits; i > 0; i--)
        printf("%c",((num >> i-1) & 1) ? '1':'0');

    return 0;
}
