/*
In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:
    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?

https://projecteuler.net/problem=31
*/

#include <iostream>
#include <vector>

#define COIN_COUNT 8
const int coins[COIN_COUNT] = {1, 2, 5, 10, 20, 50, 100, 200};

/**
 * @brief Finds the number of coin arrangements that can
 * form the given value.
 * 
 * @param value 
 * @return number of possible arrangements of coins 
 */
int numArrangements(int value) {
    int ways[value + 1]{};
    ways[0] = 1;
 
    for (int i = 0; i < COIN_COUNT; i++) {
        for (int j = coins[i]; j <= value; j += coins[0]) {
            ways[j] += ways[j - coins[i]];
        }
    }
    
    return ways[value];
}

int main(int argc, char **argv) {
    if(argc < 2) return 1;
    int val = atoi(argv[1]);
    printf("Num of ways to arrange %dp = %d\n", val, numArrangements(val));

    return 0;
}