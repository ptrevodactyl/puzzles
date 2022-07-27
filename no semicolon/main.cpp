/*
Print numbers from 1 to N with no semicolons

https://www.techiedelight.com/print-numbers-1-n-without-using-semicolon/
*/

#include <iostream>

int main(int argc, char** argv) {
    // argv[1] is n, store value in argc
    while((argc++ <= (atoi(argv[1]) + 1)) ? printf("%d, ", argc - 2) : 0) {}
}