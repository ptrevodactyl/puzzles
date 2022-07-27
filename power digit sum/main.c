/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

https://projecteuler.net/problem=16
*/

#include <stdio.h>

#define POWER 1000
#define NUMDIGITS 1000

int main(int argc, char **argv) {
    int digits[NUMDIGITS] = {0};
    int i, j, temp, carry, sum = 0;
    digits[0] = 1;

    for(i = 0; i < POWER; i++) {
        carry = 0;

        for(j = 0; j < NUMDIGITS; j++) {
            temp = 2 * digits[j] + carry;
            carry = 0;

            if(temp > 9) {
                digits[j] = temp % 10;
                carry = temp / 10;
            } else {
                digits[j] = temp;
            }
        }
    }

    i = NUMDIGITS;
    while(!digits[--i]);
    for(; i >= 0; i--) {
        printf("%d", digits[i]);
        sum += digits[i];
        
    }
    printf("\n%d\n", sum);

    return 0;
}