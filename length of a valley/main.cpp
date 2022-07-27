/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/hill-150045b2/
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

int main(int argc, char **argv) {

    int T, N, i;
    T = fast_read();
    while(T--) {
        N = fast_read();
        int A[N], l = 0, r = 0;
        for(i = 0; i < N; i++) A[i] = fast_read();
        int out[N]{0};

        for(i = 1; i < N; ++i) {
            A[i] < A[i - 1] ? ++l : l = 0;
            out[i] += l;
        }
        for(i = N - 2; i >= 0; --i) {
            A[i] < A[i + 1] ? ++r : r = 0;
            out[i] += r;
        }
        for(i = 0; i < N; ++i) std::cout << out[i] + 1 << " ";
        std::cout << "\n";
    }

    return 0;
}