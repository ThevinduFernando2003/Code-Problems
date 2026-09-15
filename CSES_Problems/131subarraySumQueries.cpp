#include <bits/stdc++.h>
using namespace std;

/*
CSES - Subarray Sum Queries

Set a[k]=x, print maximum subarray sum (empty subarray allowed, sum 0).

Pseudocode
----------
segment node: sum, pref, suff, best
merge: best = max(L.best, R.best, L.suff+R.pref)
update leaf then print max(0, root.best)
*/

struct Node {
    long long sum = 0, pref = 0, suff = 0, best = 0;
};

Node merge(const Node& a, const Node& b) {
    Node r;
    r.sum = a.sum + b.sum;
    r.pref = max(a.pref, a.sum + b.pref);
    r.suff = max(b.suff, b.sum + a.suff);
    r.best = max({a.best, b.best, a.suff + b.pref});
    return r;
}

int n;
vector<Node> t;

void upd(int v, int l, int r, int pos, long long val) {
    if (l == r) {
        t[v] = {val, val, val, val};
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) upd(v * 2, l, m, pos, val);
    else upd(v * 2 + 1, m + 1, r, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    t.resize(4 * n);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        upd(1, 1, n, i, x);
    }
    while (q--) {
        int k;
        long long x;
        cin >> k >> x;
        upd(1, 1, n, k, x);
        cout << max(0LL, t[1].best) << "\n";
    }
    return 0;
}
