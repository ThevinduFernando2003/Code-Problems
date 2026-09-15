#include <bits/stdc++.h>
using namespace std;

/*
CSES - Hamiltonian Flights

Number of Hamiltonian paths from 1 to n, modulo 1e9+7. n <= 20.

Pseudocode
----------
dp[mask][v] = paths that visit exactly the cities in mask and end at v
start dp[1][1] = 1  (city 1 is bit 0)
from each state, fly to an unused neighbor
answer dp[(1<<n)-1][n]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MOD = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<int> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a] |= 1 << b;
    }
    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n));
    dp[1][0] = 1;
    for (int mask = 1; mask < N; mask++) {
        if (!(mask & 1)) continue;
        for (int u = 0; u < n; u++) if ((mask >> u & 1) && dp[mask][u]) {
            int can = adj[u] & ~mask;
            for (int v = 0; v < n; v++) if (can >> v & 1) {
                dp[mask | (1 << v)][v] = (dp[mask | (1 << v)][v] + dp[mask][u]) % MOD;
            }
        }
    }
    cout << dp[N - 1][n - 1] << "\n";
    return 0;
}
