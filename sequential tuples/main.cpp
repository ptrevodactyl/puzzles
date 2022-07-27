/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/sequential-tuples-ea494c73/

it's just math lol
*/

#include <iostream>

int main() {
    std::iostream::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

    int T, N; std::cin >> T;

    while(T--) {
        std::cin >> N;
        switch(N) {
            case 1:
                std::cout << 1 << "\n";
                break;
            case 2:
                std::cout << 4 << "\n";
                break;
            case 3:
                std::cout << 10 << "\n";
                break;
            default:
                std::cout << (9 * (N - 2)) << "\n";
                break;
        }
    }

    return 0;   
}