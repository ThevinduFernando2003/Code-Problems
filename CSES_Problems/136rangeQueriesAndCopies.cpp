#include <bits/stdc++.h>
using namespace std;

/*
CSES - Range Queries and Copies

Persistent arrays: range sum, point set, clone.

Pseudocode
----------
persistent segment tree
roots[0] := initial array
type 1 k a b: query roots[k] on [a,b]
type 2 k a x: roots[k] := update(roots[k], a, x)
type 3 k: append a new root equal to roots[k]
*/

struct Node {
    long long sum;
    int l, r;
};

vector<Node> st;
int n;

int newNode(long long sum, int l, int r) {
    st.push_back({sum, l, r});
    return (int)st.size() - 1;
}

int build(int l, int r, vector<long long>& a) {
    if (l == r) return newNode(a[l], 0, 0);
    int m = (l + r) / 2;
    int L = build(l, m, a), R = build(m + 1, r, a);
    return newNode(st[L].sum + st[R].sum, L, R);
}

int upd(int v, int l, int r, int pos, long long val) {
    if (l == r) return newNode(val, 0, 0);
    int m = (l + r) / 2;
    int L = st[v].l, R = st[v].r;
    if (pos <= m) L = upd(L, l, m, pos, val);
    else R = upd(R, m + 1, r, pos, val);
    return newNode(st[L].sum + st[R].sum, L, R);
}

long long query(int v, int l, int r, int ql, int qr) {
    if (!v || qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return st[v].sum;
    int m = (l + r) / 2;
    return query(st[v].l, l, m, ql, qr) + query(st[v].r, m + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    st.reserve((n + q) * 20);
    st.push_back({0, 0, 0});
    vector<int> root = {0, build(1, n, a)};
    while (q--) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            cout << query(root[k], 1, n, a, b) << "\n";
        } else if (t == 2) {
            int a;
            long long x;
            cin >> a >> x;
            root[k] = upd(root[k], 1, n, a, x);
        } else {
            root.push_back(root[k]);
        }
    }
    return 0;
}
