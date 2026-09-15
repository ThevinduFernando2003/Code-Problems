#include <bits/stdc++.h>
using namespace std;

/*
CSES - Nested Ranges Check

For each range, print whether it contains some other range, then whether
it is contained in some other range.

Pseudocode
----------
compress all right endpoints
sort ranges by left ascending, right descending, keep original index
scan left to right:
    a range contains a previous one if some already-seen right is <= this right
    (previous ranges start no later and have larger-or-equal right because of the sort)
scan right to left for "contained by"
Fenwick stores counts of seen right endpoints
*/

struct Range {
    int l, r, id;
};

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1) {}
    void add(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Range> a(n);
    vector<int> rs(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
        rs[i] = a[i].r;
    }
    sort(rs.begin(), rs.end());
    rs.erase(unique(rs.begin(), rs.end()), rs.end());
    auto idr = [&](int x) {
        return (int)(lower_bound(rs.begin(), rs.end(), x) - rs.begin()) + 1;
    };
    sort(a.begin(), a.end(), [](const Range& x, const Range& y) {
        if (x.l != y.l) return x.l < y.l;
        return x.r > y.r;
    });
    int m = (int)rs.size();
    Fenwick fw(m);
    vector<int> contains(n), contained(n);
    for (int i = 0; i < n; i++) {
        int r = idr(a[i].r);
        contained[a[i].id] = fw.sum(m) - fw.sum(r - 1) > 0;
        fw.add(r, 1);
    }
    fw = Fenwick(m);
    for (int i = n - 1; i >= 0; i--) {
        int r = idr(a[i].r);
        contains[a[i].id] = fw.sum(r) > 0;
        fw.add(r, 1);
    }
    for (int i = 0; i < n; i++) cout << contains[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++) cout << contained[i] << " \n"[i == n - 1];
    return 0;
}
