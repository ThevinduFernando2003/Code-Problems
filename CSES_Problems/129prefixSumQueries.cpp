#include <bits/stdc++.h>
using namespace std;

/*
CSES - Prefix Sum Queries

Max prefix sum of subarray [a,b], empty prefix 0 allowed.

Pseudocode
----------
segment node stores (sum, max_prefix)
merge(L,R): sum = L.sum+R.sum, max_prefix = max(L.max_prefix, L.sum+R.max_prefix)
query [a,b]: merge nodes left to right
answer max(0, node.max_prefix)
*/

struct Node {
    long long sum = 0, pref = 0;
};

Node merge(const Node& a, const Node& b) {
    Node r;
    r.sum = a.sum + b.sum;
    r.pref = max(a.pref, a.sum + b.pref);
    return r;
}

int n;
vector<Node> t;

void build(int v, int l, int r, vector<long long>& a) {
    if (l == r) {
        t[v] = {a[l], a[l]};
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m, a);
    build(v * 2 + 1, m + 1, r, a);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, long long val) {
    if (l == r) {
        t[v] = {val, val};
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) upd(v * 2, l, m, pos, val);
    else upd(v * 2 + 1, m + 1, r, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

Node query(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return {0, LLONG_MIN / 4};
    if (ql <= l && r <= qr) return t[v];
    int m = (l + r) / 2;
    return merge(query(v * 2, l, m, ql, qr), query(v * 2 + 1, m + 1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    t.resize(4 * n);
    build(1, 1, n, a);
    while (q--) {
        int tpe;
        cin >> tpe;
        if (tpe == 1) {
            int k;
            long long u;
            cin >> k >> u;
            upd(1, 1, n, k, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << max(0LL, query(1, 1, n, a, b).pref) << "\n";
        }
    }
    return 0;
}
