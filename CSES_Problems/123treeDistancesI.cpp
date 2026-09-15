#include <bits/stdc++.h>
using namespace std;

/*
CSES - Tree Distances I

For every node, the maximum distance to any other node.

Pseudocode
----------
two DFS:
    down[u] := 1 + max down[child]
    up[child] := 1 + max(up[u], best other child's down)
answer[u] := max(down[u], up[u])
*/

int n;
vector<vector<int>> adj;
vector<int> down, up, ans;

void dfs1(int u, int p) {
    down[u] = 0;
    for (int v : adj[u]) if (v != p) {
        dfs1(v, u);
        down[u] = max(down[u], down[v] + 1);
    }
}

void dfs2(int u, int p) {
    ans[u] = max(down[u], up[u]);
    int mx1 = -1, mx2 = -1;
    for (int v : adj[u]) if (v != p) {
        int d = down[v] + 1;
        if (d > mx1) {
            mx2 = mx1;
            mx1 = d;
        } else mx2 = max(mx2, d);
    }
    for (int v : adj[u]) if (v != p) {
        int use = (down[v] + 1 == mx1) ? mx2 : mx1;
        up[v] = 1 + max(up[u], max(0, use));
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n + 1, {});
    down.assign(n + 1, 0);
    up.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}
