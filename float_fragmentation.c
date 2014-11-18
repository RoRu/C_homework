#include <stdio.h>

union {
    float fnum;
    struct {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        int sign : 1;
    } bitField;
} fragm;

int main(void) {
    float f = 0;
    scanf("%f", &f);

    fragm.fnum = f;

    int i = 0;
    float t = 0,
          mant = 0;
    for(i = 22, t = 0.5; i >= 0; i--, t /= 2) {
        mant += ((fragm.bitField.mantissa >> i) & 1) * t;
    }

    printf("Sign = %d\nExponent = %d\nFraction = %f", fragm.bitField.sign, fragm.bitField.exponent, mant);
    return 0;
}
