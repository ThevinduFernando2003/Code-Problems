#include <bits/stdc++.h>
using namespace std;

/*
CSES - Tree Distances II

For every node, sum of distances to all other nodes.

Pseudocode
----------
dfs1: subtree sizes and down[u] = sum of distances in subtree
dfs2 reroot:
    up contribution from parent: ans[p] - down[u] - sz[u]  (nodes outside)
    plus sz[u] becoming n - sz[u] extra steps
    ans[u] := down[u] + (ans[p] - down[u] - sz[u]) + (n - sz[u])
*/

int n;
vector<vector<int>> adj;
vector<int> sz;
vector<long long> down, ans;

void dfs1(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dfs1(v, u);
        sz[u] += sz[v];
        down[u] += down[v] + sz[v];
    }
}

void dfs2(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        ans[v] = ans[u] - sz[v] + (n - sz[v]);
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sz.assign(n + 1, 0);
    down.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    dfs1(1, 0);
    ans[1] = down[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}
