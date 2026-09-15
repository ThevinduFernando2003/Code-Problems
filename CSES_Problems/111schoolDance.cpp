#include <bits/stdc++.h>
using namespace std;

/*
CSES - School Dance

Maximum bipartite matching boys-girls. Print the pairs.

Pseudocode
----------
Kuhn: DFS augmenting paths from each boy
alt: try unused girls, or rematch the boy currently matched to that girl
*/

int n, m, k;
vector<vector<int>> adj;
vector<int> matchR, vis;

bool dfs(int u) {
    for (int v : adj[u]) if (!vis[v]) {
        vis[v] = 1;
        if (!matchR[v] || dfs(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    adj.assign(n + 1, {});
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    matchR.assign(m + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vis.assign(m + 1, 0);
        if (dfs(i)) ans++;
    }
    cout << ans << "\n";
    for (int g = 1; g <= m; g++) if (matchR[g]) cout << matchR[g] << " " << g << "\n";
    return 0;
}
