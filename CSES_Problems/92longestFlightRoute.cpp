#include <bits/stdc++.h>
using namespace std;

/*
CSES - Longest Flight Route

Longest path from 1 to n in a directed acyclic flight graph.

Pseudocode
----------
topological order
dp[1] := 1, parent[1] := 0
for u in topo:
    for v in adj[u]:
        if dp[u] and dp[u]+1 > dp[v]:
            dp[v] := dp[u]+1, parent[v] := u
if dp[n] == 0: IMPOSSIBLE
else unwind parent from n
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    vector<int> dp(n + 1), par(n + 1);
    dp[1] = 1;
    for (int u : topo) {
        if (!dp[u]) continue;
        for (int v : adj[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                par[v] = u;
            }
        }
    }
    if (!dp[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    for (int v = n; v; v = par[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++) cout << path[i] << " \n"[i + 1 == (int)path.size()];
    return 0;
}
