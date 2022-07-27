/*
 Fastest Solution
 */

#include <iostream>     
     
int fast_read() {
    char c;
    do c = getchar();
    while(c < '0' || c > '9');
 
    int S = 0;
    while(c >= '0' && c <= '9') {
        S = (S << 1) + (S << 3) + (c - '0');
        c = getchar();
    }
    return S;
}

int i;
int main() {
    int t; t = fast_read();
    while(t--) {
        int n, l = 0, r = 0;
        n = fast_read();
        int v[n + 1], rasp[n + 1];

        // initialize arrays
        for (i = 1; i <= n; ++i) rasp[i] = 0;
        for (i = 1; i <= n; ++i) v[i] = fast_read();
            
        // left
        for (i = 2; i <= n; ++i) {
            if (v[i] < v[i - 1]) ++l;
            else l = 0;
            rasp[i] += l;
        }

        // right
        for (i = n - 1; i >= 1; --i) {
            if (v[i] < v[i + 1]) ++r;
            else r = 0;
            rasp[i] += r;
        }

        for (i = 1; i <= n; ++i) std::cout << rasp[i] + 1 << ' ';
    	std::cout << '\n';
    }
     
    return 0;
}
