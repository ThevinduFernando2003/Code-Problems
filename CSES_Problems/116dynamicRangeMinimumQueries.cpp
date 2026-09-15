#include <bits/stdc++.h>
using namespace std;

/*
CSES - Dynamic Range Minimum Queries

Point updates and range minima.

Pseudocode
----------
segment tree, each node stores min of its segment
update walks to a leaf and rebuilds mins on the way up
query splits the interval into O(log n) nodes
*/

int n;
vector<int> st;

void upd(int i, int x) {
    st[i += n] = x;
    for (i /= 2; i; i /= 2) st[i] = min(st[i * 2], st[i * 2 + 1]);
}

int qry(int l, int r) {
    int res = INT_MAX;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res = min(res, st[l++]);
        if (r & 1) res = min(res, st[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    st.assign(2 * n, INT_MAX);
    for (int i = 0; i < n; i++) cin >> st[n + i];
    for (int i = n - 1; i > 0; i--) st[i] = min(st[i * 2], st[i * 2 + 1]);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x;
            upd(k - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << qry(l - 1, r) << "\n";
        }
    }
    return 0;
}
