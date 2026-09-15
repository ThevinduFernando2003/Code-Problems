#include <bits/stdc++.h>
using namespace std;

/*
CSES - Road Reparation

Minimum cost to connect all cities, or IMPOSSIBLE.

Pseudocode
----------
Kruskal: sort edges by cost
union-find, add an edge if it joins two components
if n-1 edges were added, print the cost
*/

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n + 1), sz(n + 1, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i++) cin >> e[i][1] >> e[i][2] >> e[i][0];
    sort(e.begin(), e.end());
    DSU dsu(n);
    long long cost = 0;
    int used = 0;
    for (auto [w, a, b] : e) if (dsu.unite(a, b)) {
        cost += w;
        used++;
    }
    if (used != n - 1) cout << "IMPOSSIBLE\n";
    else cout << cost << "\n";
    return 0;
}
