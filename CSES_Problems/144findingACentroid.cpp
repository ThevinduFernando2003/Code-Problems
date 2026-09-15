#include <bits/stdc++.h>
using namespace std;

/*
CSES - Finding a Centroid

A centroid has every adjacent subtree of size <= n/2.

Pseudocode
----------
compute subtree sizes from any root
walk from the root to a child while sz[child] > n/2
the node we stop at is a centroid
*/

int n;
vector<vector<int>> adj;
vector<int> sz;

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int p) {
    for (int v : adj[u]) if (v != p && sz[v] > n / 2) return centroid(v, u);
    return u;
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
    dfs(1, 0);
    cout << centroid(1, 0) << "\n";
    return 0;
}
