#include <bits/stdc++.h>
using namespace std;

/*
CSES - Counting Paths

Add 1 to every node on m paths, then print all node values.

Pseudocode
----------
for each path a-b:
    diff[a]++, diff[b]++, diff[lca]--, diff[parent[lca]]--
dfs from root: val[u] := diff[u] + sum of children
*/

const int LOG = 19;
int n;
vector<vector<int>> adj, up;
vector<int> dep, diff, val, par;

void dfs0(int u, int p) {
    par[u] = p;
    up[u][0] = p;
    for (int j = 1; j < LOG; j++) up[u][j] = up[up[u][j - 1]][j - 1];
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs0(v, u);
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

void dfs1(int u, int p) {
    val[u] = diff[u];
    for (int v : adj[u]) if (v != p) {
        dfs1(v, u);
        val[u] += val[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    up.assign(n + 1, vector<int>(LOG));
    dep.assign(n + 1, 0);
    par.assign(n + 1, 0);
    dfs0(1, 0);
    diff.assign(n + 1, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);
        diff[a]++;
        diff[b]++;
        diff[c]--;
        if (par[c]) diff[par[c]]--;
    }
    val.assign(n + 1, 0);
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) cout << val[i] << " \n"[i == n];
    return 0;
}
