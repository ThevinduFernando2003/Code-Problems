#include <bits/stdc++.h>
using namespace std;

/*
CSES - Dynamic Range Sum Queries

Point updates and range sums.

Pseudocode
----------
Fenwick tree
update i x: add (x - old[i]) at i
query l r: sum(r) - sum(l-1)
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fw.add(i, a[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            long long x;
            cin >> k >> x;
            fw.add(k, x - a[k]);
            a[k] = x;
        } else {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(r) - fw.sum(l - 1) << "\n";
        }
    }
    return 0;
}
