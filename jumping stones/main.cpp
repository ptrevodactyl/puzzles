/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/jump-k-forward-250d464b/
*/

#include <iostream>

#define MOD 1000000007

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false), std::cin.tie(0);
    int n, k; std::cin >> n >> k;

    int ways[n + 1]{0, 1};
    for(int i = 2; i <= n; i++) {
        long long res = 0;
        for(int j = ((i - k < 0) ? 0 : i - k); j < i; j++) res += ways[j];
        ways[i] = (int) (res % MOD);
    }

    std::cout << ways[n] << std::endl;
    return 0;
}