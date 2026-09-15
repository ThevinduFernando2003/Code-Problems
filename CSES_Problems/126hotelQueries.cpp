#include <bits/stdc++.h>
using namespace std;

/*
CSES - Hotel Queries

Assign each group to the leftmost hotel with enough rooms.

Pseudocode
----------
segment tree storing max free rooms in a range
for each group of size r:
    if tree.max(1,n) < r: print 0
    else walk left while left.max >= r, else right
    assign that hotel, subtract r, update leaf
*/

int n, m;
vector<int> t;

void build(int v, int l, int r, vector<int>& h) {
    if (l == r) {
        t[v] = h[l];
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m, h);
    build(v * 2 + 1, m + 1, r, h);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int query(int v, int l, int r, int need) {
    if (t[v] < need) return 0;
    if (l == r) return l;
    int m = (l + r) / 2;
    if (t[v * 2] >= need) return query(v * 2, l, m, need);
    return query(v * 2 + 1, m + 1, r, need);
}

void upd(int v, int l, int r, int pos, int val) {
    if (l == r) {
        t[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) upd(v * 2, l, m, pos, val);
    else upd(v * 2 + 1, m + 1, r, pos, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    t.assign(4 * n, 0);
    build(1, 1, n, h);
    for (int i = 0; i < m; i++) {
        int r;
        cin >> r;
        int idx = query(1, 1, n, r);
        cout << idx << " \n"[i + 1 == m];
        if (idx) {
            h[idx] -= r;
            upd(1, 1, n, idx, h[idx]);
        }
    }
    return 0;
}
