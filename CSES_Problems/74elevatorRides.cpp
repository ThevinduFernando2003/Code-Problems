#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    const long long INF = 1e18;
    vector<long long> dp(1 << n, INF);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == INF) {
            continue;
        }

        int count = __builtin_popcount(mask);
        if (count == n) {
            continue;
        }

        long long rideWeight = 0;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                rideWeight += weights[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                continue;
            }
            int nextMask = mask | (1 << i);
            dp[nextMask] = min(dp[nextMask], max(dp[mask], rideWeight));
        }
    }

    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
