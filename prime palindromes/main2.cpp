/*
A faster implementation that can solve up to 11953 primes


*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
 
void nextPal(std::vector<int> &s) {
    int len = s.size();
    for (int n = (len + 1) / 2; n > 0; n--) {
        if (s[n - 1] < 9) { 
            s[len - n] = s[n - 1] = s[n - 1] + 1;
            return;
        } else {
            s[len - n] = s[n - 1] = 0;
        }
    }
    // wrap around to all zero, so extend
    s[0] = 1; 
    s.push_back(1);
}
 
int toInt(std::vector<int> s) {
    int n = 0, r = 1;
    for (int i = 0; i != (int) s.size(); i++) {
        n += s[i] * r;
        r *= 10;
    }
    return n;
}
 
bool isPrime(int n) {
    int max = sqrt(n);
    for (int i = 3; i <= max; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
 
int check(const std::vector<int> &s) {
    if (s.size() % 2 == 0) return -1;
    if (s[0] % 2 == 0 || s[0] == 5) return -1;
    int n = toInt(s);
    if (!isPrime(n)) return -1;
    return n;
}
 
int main(int argc, char *argv[]) {
    int count = std::atoi(argv[1]) - 5;
    std::vector<int> s = { 1, 0, 1 };
    int p = -1;
    while (count > 0) {
        p = check(s);
        if (p >= 0) count--;
        nextPal(s);
    }
    std::cout << p << "\n";
}