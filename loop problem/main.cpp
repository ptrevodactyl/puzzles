/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/loop-problem-db615209/
I gave up on this one
*/

#include <iostream>
#include <algorithm>

#define MOD 1000000007

int main(int argc, char **argv) {
    std::iostream::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

    int sum, N, A, B, C, D;
    //std::cin >> N;
    N = 1;
    while(N--) {
        sum = 0;
        std::cin >> A >> B >> C >> D;
        for(int i = A; i <= B; i++) {
            int xors[D - C + 1]{};
            for(int j = C; j <= D; j++) {
                xors[j - C] = i^j;
                // std::cout << "  (" << sum << " + " << i << "^" << j << ")" << '\n';
                // std::cout << "= (" << sum << " + " << (i^j) << ")" << '\n';
                sum = (sum + (i^j)) % MOD;
                // std::cout << "= " << sum << "\n  ---------------------------------------" << std::endl;
            }
            //std::sort(&xors[0], &xors[D - C]);
            for(int i = 0; i <= D - C; i++) {
                //if(xors[i] != xors[i - 1] + 1)
                    std::cout << xors[i] << '\n';
            }
            std::cout << "sum = " << sum << std::endl;
            
        }

        //std::cout << sum << '\n';
    }

    return 0;
}