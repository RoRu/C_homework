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

    printf("Choose the way to translate:\n1. Pointers (enter 1)\n2. Union (enter any other number)\n");
    int dec = 0,
        intf = 0;
    scanf("%d", &dec);
    if(dec == 1) {
        intf = bitFloatToInt1(f);
    }
    else {
        intf = bitFloatToInt2(f);
    }


    int sign = !!(intf >> 31);

    int exp = 0,
        i = 0,
        k = 1;
    for(i = 23, k = 1; i < 31; i++, k *= 2) {
        exp += !!((intf >> i) & 1) * k;
    }

    float frac = 0,
          t = 0.5;
    for(i = 22, t = 0.5; i >= 0; i--, t /= 2) {
        frac += !!((intf >> i) & 1) * t;
    }
    printf("Sign = %d\nExponent = %d\nFraction = %f", sign, exp, frac);
    return 0;
}