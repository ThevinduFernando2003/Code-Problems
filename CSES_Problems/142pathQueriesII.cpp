#include <bits/stdc++.h>
using namespace std;

/*
CSES - Path Queries II

Update a node value, query the maximum on the path a-b.

Pseudocode
----------
heavy-light decomposition
segment tree of node values in DFS order
path a-b: while heads differ, query the deeper chain, jump to parent of head
then query the remaining segment on one chain
*/

int n;
vector<vector<int>> adj;
vector<int> sz, dep, par, heavy, head, pos, val;
vector<int> t;
int cur;

void dfs(int u, int p) {
    sz[u] = 1;
    par[u] = p;
    int mx = 0;
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > mx) {
            mx = sz[v];
            heavy[u] = v;
        }
    }
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = ++cur;
    if (heavy[u]) decompose(heavy[u], h);
    for (int v : adj[u]) if (v != par[u] && v != heavy[u]) decompose(v, v);
}

void upd(int v, int l, int r, int p, int x) {
    if (l == r) {
        t[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (p <= m) upd(v * 2, l, m, p, x);
    else upd(v * 2 + 1, m + 1, r, p, x);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int qry(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return t[v];
    int m = (l + r) / 2;
    return max(qry(v * 2, l, m, ql, qr), qry(v * 2 + 1, m + 1, r, ql, qr));
}

int pathMax(int a, int b) {
    int ans = 0;
    while (head[a] != head[b]) {
        if (dep[head[a]] < dep[head[b]]) swap(a, b);
        ans = max(ans, qry(1, 1, n, pos[head[a]], pos[a]));
        a = par[head[a]];
    }
    if (pos[a] > pos[b]) swap(a, b);
    ans = max(ans, qry(1, 1, n, pos[a], pos[b]));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    val.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> val[i];
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sz.assign(n + 1, 0);
    dep.assign(n + 1, 0);
    par.assign(n + 1, 0);
    heavy.assign(n + 1, 0);
    head.assign(n + 1, 0);
    pos.assign(n + 1, 0);
    dfs(1, 0);
    decompose(1, 1);
    t.assign(4 * n, 0);
    for (int i = 1; i <= n; i++) upd(1, 1, n, pos[i], val[i]);
    while (q--) {
        int tpe;
        cin >> tpe;
        if (tpe == 1) {
            int s, x;
            cin >> s >> x;
            upd(1, 1, n, pos[s], x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << pathMax(a, b) << "\n";
        }
    }
    return 0;
}
