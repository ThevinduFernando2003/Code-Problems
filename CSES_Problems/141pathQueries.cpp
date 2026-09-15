#include <bits/stdc++.h>
using namespace std;

/*
CSES - Path Queries

Set a node value, query the sum on the path from root 1 to s.

Pseudocode
----------
Euler tour in/out
Fenwick +val at in[u], -val at out[u]+1
path-to-root(s) = prefix sum up to in[s]
*/

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n) : n(n), bit(n + 2) {}
    void add(int i, long long v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    long long sum(int i) {
        long long s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

int n, timer;
vector<vector<int>> adj;
vector<int> in, outt;
vector<long long> val;

void dfs(int u, int p) {
    in[u] = ++timer;
    for (int v : adj[u]) if (v != p) dfs(v, u);
    outt[u] = timer;
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
    in.assign(n + 1, 0);
    outt.assign(n + 1, 0);
    dfs(1, 0);
    Fenwick fw(n + 1);
    for (int i = 1; i <= n; i++) {
        fw.add(in[i], val[i]);
        fw.add(outt[i] + 1, -val[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s;
            long long x;
            cin >> s >> x;
            long long d = x - val[s];
            val[s] = x;
            fw.add(in[s], d);
            fw.add(outt[s] + 1, -d);
        } else {
            int s;
            cin >> s;
            cout << fw.sum(in[s]) << "\n";
        }
    }
    return 0;
}
