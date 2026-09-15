#include <bits/stdc++.h>
using namespace std;

/*
CSES - Polynomial Queries

Add 1,2,3,... on [L,R] (position L gets 1) and query range sums.

Pseudocode
----------
lazy: add B + C*i to every index i in a node
type 1 [L,R]: add (1-L) + 1*i on that range
push the same (B,C) to both children
sum of B+C*i over [l,r] = B*(r-l+1) + C*(l+r)*(r-l+1)/2
*/

int n;
vector<long long> t, lzB, lzC;

void apply(int v, int l, int r, long long B, long long C) {
    long long len = r - l + 1;
    t[v] += B * len + C * (l + r) * len / 2;
    lzB[v] += B;
    lzC[v] += C;
}

void push(int v, int l, int r) {
    if (!lzB[v] && !lzC[v]) return;
    int m = (l + r) / 2;
    apply(v * 2, l, m, lzB[v], lzC[v]);
    apply(v * 2 + 1, m + 1, r, lzB[v], lzC[v]);
    lzB[v] = lzC[v] = 0;
}

void add(int v, int l, int r, int ql, int qr, long long B, long long C) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        apply(v, l, r, B, C);
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    add(v * 2, l, m, ql, qr, B, C);
    add(v * 2 + 1, m + 1, r, ql, qr, B, C);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

long long query(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return t[v];
    push(v, l, r);
    int m = (l + r) / 2;
    return query(v * 2, l, m, ql, qr) + query(v * 2 + 1, m + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    t.assign(4 * n, 0);
    lzB.assign(4 * n, 0);
    lzC.assign(4 * n, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        add(1, 1, n, i, i, x, 0);
    }
    while (q--) {
        int tpe, a, b;
        cin >> tpe >> a >> b;
        if (tpe == 1) add(1, 1, n, a, b, 1 - a, 1);
        else cout << query(1, 1, n, a, b) << "\n";
    }
    return 0;
}
