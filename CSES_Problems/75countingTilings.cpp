/*
CSES - Counting Tilings

Tilings of n x m with 1x2 and 2x1, modulo 1e9+7.

Pseudocode
----------
profile DP on columns / bitmasks
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) {
        dp[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[n] << endl;
    return 0;
}
