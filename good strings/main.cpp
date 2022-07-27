/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/good-strings-2-cf18dfcb/
*/

#include <iostream>

uint64_t pairCount(uint64_t val) {
    return ((val * (val - 1)) >> 1);
}

int main(int argc, char **argv) {
    std::iostream::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int numTests; std::cin >> numTests;
    int numLines = 0;
    std::string bitStr;

    for(int i = 0; i < numTests; i++) {
        std::cin >> numLines;
        uint64_t a = 0, b = 0, c = 0;

        for(int j = 0; j < numLines; j++) {
            std::cin >> bitStr;
            bool zeros = false, ones = false;
            for(auto c : bitStr){
                zeros |= (c == '0');
                ones |= (c == '1');
            }
            if(zeros && ones) c++;
            else if(zeros) a++;
            else b++;
            
        }
        uint64_t numPairs = pairCount(a)
                          + pairCount(b)
                          + pairCount(c)
                          + a * c
                          + b * c;
        std::cout << numPairs << '\n';
    }

    return 0;
}