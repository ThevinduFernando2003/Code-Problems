#include <bits/stdc++.h>
using namespace std;

/*
CSES - Game Routes

Number of paths from 1 to n in a DAG, modulo 1e9+7.

Pseudocode
----------
topological DP
dp[1] := 1
for u in topo:
    for v in adj[u]: dp[v] += dp[u]
print dp[n]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MOD = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int u : topo) {
        for (int v : adj[u]) dp[v] = (dp[v] + dp[u]) % MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}
