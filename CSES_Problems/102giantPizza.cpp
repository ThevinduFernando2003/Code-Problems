#include <bits/stdc++.h>
using namespace std;

/*
CSES - Giant Pizza

2-SAT: each family wants at least one of two topping choices (+x or -x).
Print a valid assignment of n toppings, or IMPOSSIBLE.

Pseudocode
----------
variable x and not-x
implication: (~a => b) and (~b => a)
Kosaraju SCC
if x and ~x share an SCC: IMPOSSIBLE
otherwise x is true iff scc[x] > scc[~x]
*/

int n, m, N;
vector<vector<int>> adj, radj;
vector<int> vis, order, comp;

int pos(int x) { return x > 0 ? x : -x + n; }
int neg(int x) { return x > 0 ? x + n : -x; }

void dfs1(int u) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs1(v);
    order.push_back(u);
}
void dfs2(int u, int c) {
    comp[u] = c;
    for (int v : radj[u]) if (!comp[v]) dfs2(v, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    N = 2 * n;
    adj.assign(N + 1, {});
    radj.assign(N + 1, {});
    auto addImp = [&](int a, int b) {
        adj[a].push_back(b);
        radj[b].push_back(a);
    };
    for (int i = 0; i < m; i++) {
        char c1, c2;
        int x, y;
        cin >> c1 >> x >> c2 >> y;
        if (c1 == '-') x = -x;
        if (c2 == '-') y = -y;
        addImp(neg(x), pos(y));
        addImp(neg(y), pos(x));
    }
    vis.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) if (!vis[i]) dfs1(i);
    comp.assign(N + 1, 0);
    int id = 0;
    for (int i = (int)order.size() - 1; i >= 0; i--) if (!comp[order[i]]) dfs2(order[i], ++id);
    vector<char> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        if (comp[i] == comp[i + n]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans[i] = comp[i] > comp[i + n] ? '+' : '-';
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}
