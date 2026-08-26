#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    int maxN = t;
    vector<long long> queries(t);
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
        maxN = max(maxN, (int)queries[i]);
    }

    vector<long long> dp(maxN + 1, 0);
    if (maxN >= 0) dp[0] = 1;
    if (maxN >= 1) dp[1] = 1;
    if (maxN >= 2) dp[2] = 3;

    for (int i = 3; i <= maxN; i++) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2] + dp[i - 3]) % MOD;
    }

    for (int i = 0; i < t; i++) {
        cout << dp[queries[i]] << "\n";
    }

    return 0;
}
