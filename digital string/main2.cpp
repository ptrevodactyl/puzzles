/*
tester's solution
*/

#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

int A[100005][4];
// visited values
int visited[100005][10];
// memoized values
int memval[100005][10];
int test_num;
// possible digit values
int digit[] = {2,4,6,8};

int f(int idx, int prev) {
    // recursion base case
    if(idx == -1) return 0;
    // we already calculated this value, don't recalculate
    if(visited[idx][prev] == test_num) return memval[idx][prev];

    visited[idx][prev] = test_num;
    int ans = INF;
    for (int i = 0; i < 4; i++) {
        // can't have adjacent digits
        if(digit[i] == prev) continue;

        ans = min(ans, A[idx][i] + f(idx-1,digit[i]));
    }

    memval[idx][prev] = ans;
    return ans;
}

int main() {
    // t and n defined in problem description
    int t,n;
    scanf("%d", &t);

    for (test_num = 1; test_num <= t; test_num++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 4; j++) scanf("%d", &A[i][j]);
        }
        int ans = f(n-1,0);
        printf("%d\n", ans);
    }

    return 0;
}
