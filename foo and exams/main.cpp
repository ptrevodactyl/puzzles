/*
https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/foo-and-exams-4/
*/

#include <bits/stdc++.h>

#define T_MAX 10000

uint64_t stress_level(uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t t) {
    // F(t) = A*t^3 + B*t^2 + C*t + D <= 10^18
    return a*t*t*t + b*t*t + c*t + d;
}

uint64_t get_max_time(uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t max_stress) {
    uint64_t stress, low = 0, high = (uint64_t) std::cbrt(max_stress);
    uint64_t t = (high + low) >> 1;

    while(high > low) {
        stress = stress_level(a, b, c, d, t);

        if(stress > max_stress) high = t - 1;
        else if(stress < max_stress) low = t + 1;
        else break;

        t = (high + low) >> 1;
    }

    if(t == 0) return 0;
    return (stress_level(a, b, c, d, t) > max_stress ? t - 1 : t);
}

int main() {
    std::iostream::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    
    int num_tests; std::cin >> num_tests;
    uint64_t a, b, c, d, max_stress;
    while(num_tests--) {
        std::cin >> a >> b >> c >> d >> max_stress;
        std::cout << get_max_time(a, b, c, d, max_stress) << "\n";
    }

    return 0;
}