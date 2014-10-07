#include <stdio.h>
#include <stdlib.h>

int power(int a, int n) {
	int res = 1;
	while(n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}


int main(void) {
    int num = 0;
    int exp = 0;
    scanf("%d%d", &num, &exp);
    printf("%d", power(num, exp));
    return 0;
}
