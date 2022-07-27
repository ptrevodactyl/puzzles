/*
Count from 1 to N, printing "Fizz" if the number is divisible by 3
"Buzz" if the number is divisible by 5, "FizzBuzz" if it's divisible by both,
and just the number if it's divisible by neither.

https://programmingpraxis.com/2021/03/23/fizzbuzz/
*/

#include <iostream>
#include <string>

int fizzBuzz(int n) {
    int sum = 0;
    std::string output;
    for(int i = 1; i <= n; i++, output.clear()) {
        if(i % 3 == 0) output += "Fizz";
        if(i % 5 == 0) output += "Buzz";
        
        if(output.size() != 0) sum++;
        else output = std::to_string(i);

        std::cout << output << (i == n ? "\n" : ", ");
    }
    return sum;
}

int main(int argc, char** argv) {
    if(argc < 2) return 1;
    int n = atoi(argv[1]);
    int sum = fizzBuzz(n);

    printf("Sum = %d\n", sum);
    fflush(stdout);
}