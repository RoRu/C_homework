/* Translating number from dec to bin 
   First task in 1st semester  (bit operations)
   Yumatov Vladimir 
*/

#include <stdio.h>

int main(void) {
    int num;
    int bits = sizeof(num) * 8;

    printf("Enter the number: ");
    scanf("%d", &num);

    int i = 0;
    for (i = bits; i > 0; i--)
        printf("%d",!!((num >> i-1) & 1));

    return 0;
}
