/*
https://www.codechef.com/submit/ON_OFF
*/

#include <bits/stdc++.h>

int main() {
    std::iostream::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    
    int T, N, i; std::cin >> T;
    while(T--) {
        std::cin >> N;
        char S[N+1], R[N+1]; std::cin >> S; std::cin >> R;
        bool on = true;

        for(i = 0; i < N; i++) {
            // on == 0, R^S == 0 -> on = 0
            // on == 0, R^S == 1 -> on = 1
            // on == 1, R^S == 0 -> on = 1
            // on == 1, R^S == 1 -> on = 0
            if(R[i] ^ S[i]) on = !on;
        }
        std::cout << (on ? "1\n" : "0\n");
    }
}