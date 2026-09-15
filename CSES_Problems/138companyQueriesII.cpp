#include <bits/stdc++.h>
using namespace std;

/*
CSES - Company Queries II

Lowest common ancestor of two employees.

Pseudocode
----------
binary lifting + depths
lift the deeper node to the same depth
if equal, that is LCA
otherwise jump both while parents differ, then parent is LCA
*/

const int LOG = 19;
int n;
vector<vector<int>> adj, up;
vector<int> dep;

void dfs(int u) {
    for (int v : adj[u]) {
        dep[v] = dep[u] + 1;
        up[v][0] = u;
        for (int j = 1; j < LOG; j++) up[v][j] = up[up[v][j - 1]][j - 1];
        dfs(v);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int d = dep[a] - dep[b];
    for (int j = 0; j < LOG; j++) if (d >> j & 1) a = up[a][j];
    if (a == b) return a;
    for (int j = LOG - 1; j >= 0; j--)
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    adj.assign(n + 1, {});
    up.assign(n + 1, vector<int>(LOG));
    dep.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}
