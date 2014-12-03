/* Getting sign of a number "n"  
   First task in 1st semester (bit operations)
   Yumatov Vladimir 
*/

#include <stdio.h>

int sign(int n){
    return (n >> 31)|(!!n);
}

int main(void) {
    printf("Enter a number:\n");
    int k = 0;
    scanf("%d", &k);
    printf("%d", sign(k));
    return 0;
}
