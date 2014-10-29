/* Calculating sign, exponent and fraction of a float number "f"
   Second task in 1st semester (working with float numbers)
   Yumatov Vladimir
*/

#include <stdio.h>

int bitFloatToInt1(float fnum) {
    return *(int *)(&fnum);
}

int bitFloatToInt2(float fnum) {
    union {
        float fl;
        int unused;
    } val;
    val.fl = fnum;
    return val.unused;
}

int main(void) {
    printf("Enter a float number:");
    float f;
    scanf("%f", &f);

    int intf = 0;
    
    int k = 0;
    while((k != 1) && (k != 2)) {
        printf("Choose the way to translate:\n1. Pointers (enter 1)\n2. Union (enter 2)\n");
        scanf("%d", &k);
        switch (k) {
            case 1: {
                intf = bitFloatToInt1(f);
                break;
            }
            case 2: {
                intf = bitFloatToInt2(f);
                break;
            }
            default: {
                printf("Enter 1 or 2\n");
            }
        }
    }


    int sign = !!(intf >> 31);

    int exp = (intf >> 23) & 0xFF;

    float frac = 0,
          t = 0.5;
    int i = 0;
    for(i = 22, t = 0.5; i >= 0; i--, t /= 2) {
        frac += !!((intf >> i) & 1) * t;
    }
    printf("Sign = %d\nExponent = %d\nFraction = %f", sign, exp, frac);
    return 0;
}
