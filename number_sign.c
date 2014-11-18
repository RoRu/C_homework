/* Getting sign of a number "n"  
   First task in 1st semester (bit operations)
   Yumatov Vladimir 
*/

#include <stdio.h>

int sign(int n){
return n >> 31;
}

int main(void) {
    printf("%s", "Enter a number:\n");
    int k;
    scanf("%d", &k);
    printf("%d", sign(k));
}
