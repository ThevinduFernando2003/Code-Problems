#include <bits/stdc++.h>
using namespace std;

/*
CSES - Distance Queries

Distance between two employees in a tree.

Pseudocode
----------
binary lifting LCA
dist(a,b) := depth[a] + depth[b] - 2*depth[lca]
*/

int n, q, LOG;
vector<vector<int>> adj, up;
vector<int> depth;

void dfs(int u, int p) {
    up[u][0] = p;
    for (int j = 1; j < LOG; j++) up[u][j] = up[up[u][j - 1]][j - 1];
    for (int v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int j = 0; j < LOG; j++) if (diff >> j & 1) a = up[a][j];
    if (a == b) return a;
    for (int j = LOG - 1; j >= 0; j--) if (up[a][j] != up[b][j]) {
        a = up[a][j];
        b = up[b][j];
    }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    LOG = 1;
    while ((1 << LOG) <= n) LOG++;
    adj.assign(n + 1, {});
    up.assign(n + 1, vector<int>(LOG));
    depth.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << depth[a] + depth[b] - 2 * depth[lca(a, b)] << "\n";
    }
    return 0;
}
