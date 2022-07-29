/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/digital-string-b2b5401b/
gave up on this one
*/

#include <bits/stdc++.h>

//#define DEBUG

int main() {
    std::iostream::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    
    int T, N, i, min_i, prev_min_i; std::cin >> T;
    
    #ifdef DEBUG
    int line[4];
    int real_min_i;
    #endif

    uint64_t min, cost, final_cost;

    while(T--) {
        std::cin >> N;
        final_cost = 0;
        prev_min_i = -1;

        while(N--) {
            min = ULONG_LONG_MAX;
            min_i = 0;

            #ifdef DEBUG
            real_min_i = 0;
            #endif

            for(i = 0; i < 4; i++) {
                std::cin >> cost;

                #ifdef DEBUG
                line[i] = cost;
                if(cost < min) real_min_i = i;
                #endif

                if(i == prev_min_i) continue;
                if(cost < min) {
                    min = cost;
                    min_i = i;
                }
            }
            
            #ifdef DEBUG
            std::string color = (real_min_i == min_i ? "\033[0;32m" : "\033[0;31m");
            for(int i = 0; i < 4; i++) {
                if(i == min_i) std::cout << color << line[i] << "\033[0m ";
                else std::cout << line[i] << " ";
            }
            std::cout << "\n";
            #endif

            prev_min_i = min_i;
            final_cost += min;
        }

        #ifndef DEBUG
        std::cout << final_cost << "\n";
        #endif
    }
}