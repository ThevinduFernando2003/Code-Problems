#include <bits/stdc++.h>
using namespace std;

/*
CSES - Planets and Kingdoms

Assign a kingdom id to each strongly connected component.

Pseudocode
----------
Kosaraju:
    DFS finish order on the original graph
    DFS on the reversed graph in reverse finish order
    each tree is one SCC / kingdom
*/

int n, m;
vector<vector<int>> adj, radj;
vector<int> vis, order, king;

void dfs1(int u) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u, int k) {
    king[u] = k;
    for (int v : radj[u]) if (!king[v]) dfs2(v, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.assign(n + 1, {});
    radj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
    king.assign(n + 1, 0);
    int k = 0;
    for (int i = n - 1; i >= 0; i--) if (!king[order[i]]) dfs2(order[i], ++k);
    cout << k << "\n";
    for (int i = 1; i <= n; i++) cout << king[i] << " \n"[i == n];
    return 0;
}
