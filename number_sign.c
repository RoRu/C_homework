#include <stdio.h>

int sign(int n){
return (n >> 31)|(!!n);
}

int main(void) {
    printf("%s", "Enter a number:\n");
    int k;
    scanf("%d", &k);
    printf("%d", sign(k));
}
