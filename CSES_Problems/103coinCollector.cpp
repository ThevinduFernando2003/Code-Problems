#include <bits/stdc++.h>
using namespace std;

/*
CSES - Coin Collector

Directed graph, coins on nodes. A node may be visited at most once.
Maximum coins collectable.

Pseudocode
----------
Kosaraju SCC, sum coins inside each component
build the DAG of components
DP: max path of component sums on that DAG
*/

int n, m;
vector<vector<int>> adj, radj;
vector<int> vis, order, comp;
vector<long long> coins, sccCoins;

void dfs1(int u) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs1(v);
    order.push_back(u);
}
void dfs2(int u, int c) {
    vis[u] = 1;
    comp[u] = c;
    sccCoins[c] += coins[u];
    for (int v : radj[u]) if (!vis[v]) dfs2(v, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    coins.resize(n + 1);
    adj.assign(n + 1, {});
    radj.assign(n + 1, {});
    for (int i = 1; i <= n; i++) cin >> coins[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
    vis.assign(n + 1, 0);
    comp.assign(n + 1, 0);
    sccCoins.assign(1, 0);
    int k = 0;
    for (int i = n - 1; i >= 0; i--) if (!vis[order[i]]) {
        sccCoins.push_back(0);
        dfs2(order[i], ++k);
    }
    vector<vector<int>> dag(k + 1);
    vector<int> indeg(k + 1);
    for (int u = 1; u <= n; u++) for (int v : adj[u]) if (comp[u] != comp[v]) {
        dag[comp[u]].push_back(comp[v]);
        indeg[comp[v]]++;
    }
    vector<long long> dp = sccCoins;
    queue<int> q;
    for (int i = 1; i <= k; i++) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : dag[u]) {
            dp[v] = max(dp[v], dp[u] + sccCoins[v]);
            if (--indeg[v] == 0) q.push(v);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
