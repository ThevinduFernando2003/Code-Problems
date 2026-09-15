/*
CSES - Dice Combinations

Ways to sum to n with dice faces 1..6, modulo 1e9+7.

Pseudocode
----------
dp[0]:=1
dp[s] := sum dp[s-f] for f=1..6
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int sum = 1; sum <= n; sum++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (sum >= dice) {
                dp[sum] = (dp[sum] + dp[sum - dice]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
