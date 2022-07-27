/*
Find the 100th prime palindrome
131 is an example of a prime palindrome

https://programmingpraxis.com/2021/10/26/prime-palindromes/
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

#define MAX_PRIME 1000000

bool isPalindrome(long long num) {
    int numdigits = (int) log10(num) + 1;
    int digits[numdigits];
    for(int i = 0; i < numdigits; i++) {
        digits[i] = num % 10;
        num = (long long) (num / 10);
    }

    for(int i = 0; i < numdigits; i++) {
        if(digits[i] != digits[numdigits - i - 1]) return false;
    }
    return true;
}


void SieveOfEratosthenes(long long n, std::vector<int> &primes)
{
    std::bitset<25000000> *isPrime = new std::bitset<25000000>();
    (*isPrime)[0] = 1;
    primes.push_back(2);
    for (long long i = 3; i <= n; i += 2) {
        if ((*isPrime)[i / 2] == 0) {
            if(isPalindrome(i)) primes.push_back(i);
            for (long long j = 3 * i; j <= n; j += 2 * i)
                (*isPrime)[j / 2] = 1;
        }
    }
    delete isPrime;
}

int main(int argc, char** argv) {
    if(argc < 2) return 0;
    
    int num = atoi(argv[1]); // the nth prime palindrome to find
    if(num < 0) num *= -1;
    
    long long n = 25000000;
    std::vector<int> primes;
    SieveOfEratosthenes(n, primes);
    if(n < primes.size()) {
        std::cout << num << "th prime palindrome = " << primes[n] << std::endl;
        return 0;
    }

    std::cout << "couldn't find " << num << "th prime palindrome." << std::endl;
    return 0;
}