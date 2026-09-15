#include <bits/stdc++.h>
using namespace std;

/*
CSES - Pizzeria Queries

Min p[j] + |i-j|. Maintain two segment trees:
left:  p[j] - j   (buildings j <= i)
right: p[j] + j   (buildings j >= i)

Pseudocode
----------
answer(i) := min( min_{j<=i}(p[j]-j) + i , min_{j>=i}(p[j]+j) - i )
update both trees at k when p[k] changes
*/

const long long INF = (1LL << 60);
int n;
vector<long long> tl, tr;

void upd(vector<long long>& t, int v, int l, int r, int pos, long long val) {
    if (l == r) {
        t[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) upd(t, v * 2, l, m, pos, val);
    else upd(t, v * 2 + 1, m + 1, r, pos, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

long long qry(vector<long long>& t, int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return INF;
    if (ql <= l && r <= qr) return t[v];
    int m = (l + r) / 2;
    return min(qry(t, v * 2, l, m, ql, qr), qry(t, v * 2 + 1, m + 1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    vector<long long> p(n + 1);
    tl.assign(4 * n, INF);
    tr.assign(4 * n, INF);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        upd(tl, 1, 1, n, i, p[i] - i);
        upd(tr, 1, 1, n, i, p[i] + i);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            long long x;
            cin >> k >> x;
            p[k] = x;
            upd(tl, 1, 1, n, k, p[k] - k);
            upd(tr, 1, 1, n, k, p[k] + k);
        } else {
            int k;
            cin >> k;
            long long ans = min(qry(tl, 1, 1, n, 1, k) + k, qry(tr, 1, 1, n, k, n) - k);
            cout << ans << "\n";
        }
    }
    return 0;
}
