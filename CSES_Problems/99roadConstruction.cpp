#include <bits/stdc++.h>
using namespace std;

/*
CSES - Road Construction

After each new road, print the number of components and the size of
the largest component.

Pseudocode
----------
union-find
start with n components, max size 1
when an edge joins two sets: components--, max = max(max, new size)
*/

struct DSU {
    vector<int> p, sz;
    int comps, best = 1;
    DSU(int n) : p(n + 1), sz(n + 1, 1), comps(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        best = max(best, sz[a]);
        comps--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
        cout << dsu.comps << " " << dsu.best << "\n";
    }
    return 0;
}
