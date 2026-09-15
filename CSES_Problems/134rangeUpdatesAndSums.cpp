#include <bits/stdc++.h>
using namespace std;

/*
CSES - Range Updates and Sums

Range add, range assign, range sum.

Pseudocode
----------
lazy segment tree with two lazy tags
assign overrides previous add and assign
add on top of assign: assigned_value += x
query walks pushed nodes and sums
*/

int n;
vector<long long> t, lzAdd, lzSet;
vector<char> hasSet;

void applyAdd(int v, int l, int r, long long x) {
    t[v] += x * (r - l + 1);
    if (hasSet[v]) lzSet[v] += x;
    else lzAdd[v] += x;
}

void applySet(int v, int l, int r, long long x) {
    t[v] = x * (r - l + 1);
    hasSet[v] = 1;
    lzSet[v] = x;
    lzAdd[v] = 0;
}

void push(int v, int l, int r) {
    int m = (l + r) / 2;
    if (hasSet[v]) {
        applySet(v * 2, l, m, lzSet[v]);
        applySet(v * 2 + 1, m + 1, r, lzSet[v]);
        hasSet[v] = 0;
    }
    if (lzAdd[v]) {
        applyAdd(v * 2, l, m, lzAdd[v]);
        applyAdd(v * 2 + 1, m + 1, r, lzAdd[v]);
        lzAdd[v] = 0;
    }
}

void add(int v, int l, int r, int ql, int qr, long long x) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        applyAdd(v, l, r, x);
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    add(v * 2, l, m, ql, qr, x);
    add(v * 2 + 1, m + 1, r, ql, qr, x);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

void assign(int v, int l, int r, int ql, int qr, long long x) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        applySet(v, l, r, x);
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    assign(v * 2, l, m, ql, qr, x);
    assign(v * 2 + 1, m + 1, r, ql, qr, x);
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
    lzAdd.assign(4 * n, 0);
    lzSet.assign(4 * n, 0);
    hasSet.assign(4 * n, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        assign(1, 1, n, i, i, x);
    }
    while (q--) {
        int tpe;
        cin >> tpe;
        if (tpe == 1) {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            add(1, 1, n, a, b, x);
        } else if (tpe == 2) {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            assign(1, 1, n, a, b, x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
    return 0;
}
