#include <bits/stdc++.h>
using namespace std;

/*
CSES - Subtree Queries

Set a node value, query sum of values in its subtree.

Pseudocode
----------
Euler tour: in[u]..out[u] is the subtree interval
Fenwick: add delta at in[u]
subtree sum = prefix(out[u]) - prefix(in[u]-1)
*/

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n) : n(n), bit(n + 1) {}
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
vector<int> in, out;
vector<long long> val;

void dfs(int u, int p) {
    in[u] = ++timer;
    for (int v : adj[u]) if (v != p) dfs(v, u);
    out[u] = timer;
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
    out.assign(n + 1, 0);
    dfs(1, 0);
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) fw.add(in[i], val[i]);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s;
            long long x;
            cin >> s >> x;
            fw.add(in[s], x - val[s]);
            val[s] = x;
        } else {
            int s;
            cin >> s;
            cout << fw.sum(out[s]) - fw.sum(in[s] - 1) << "\n";
        }
    }
    return 0;
}
