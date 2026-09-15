#include <bits/stdc++.h>
using namespace std;

/*
CSES - Range Update Queries

Add x to a[l..r], then answer point queries.

Pseudocode
----------
difference array in a Fenwick tree
add x on [l,r]: add +x at l, add -x at r+1
point k: prefix sum up to k
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    Fenwick fw(n);
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            fw.add(l, x);
            fw.add(r + 1, -x);
        } else {
            int k;
            cin >> k;
            cout << a[k] + fw.sum(k) << "\n";
        }
    }
    return 0;
}
