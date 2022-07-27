/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/ternary-palindromes-f57bd003/
*/

#include <iostream>

int main() {
    std::iostream::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

    int T; std::cin >> T;
    while(T--) {
        std::string s; std::cin >> s;
        int count[3]{};
        
        for(char c : s) count[c - '0']++;

        if(abs(count[0] - count[1]) > 1 || abs(count[0] - count[2]) > 1 || abs(count[1] - count[2]) > 1) std::cout << 0 << "\n";
        else if(count[0] == count[1] && count[1] == count[2]) std::cout << 6 << "\n";
        else std::cout << 2 << "\n";
    }

    return 0;
}