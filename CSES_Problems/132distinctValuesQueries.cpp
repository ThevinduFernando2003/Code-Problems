#include <bits/stdc++.h>
using namespace std;

/*
CSES - Distinct Values Queries

Count distinct values in [a,b].

Pseudocode
----------
offline: sort queries by right endpoint
scan i = 1..n
    if a[i] appeared before, Fenwick -1 at last[a[i]]
    Fenwick +1 at i, last[a[i]] := i
    answer every query ending at i: sum(b) - sum(a-1)
*/

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<pair<int, int>>> qs(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qs[r].push_back({l, i});
    }
    Fenwick fw(n);
    unordered_map<int, int> last;
    last.reserve(n * 2);
    vector<int> ans(q);
    for (int i = 1; i <= n; i++) {
        if (last.count(a[i])) fw.add(last[a[i]], -1);
        fw.add(i, 1);
        last[a[i]] = i;
        for (auto [l, id] : qs[i]) ans[id] = fw.sum(i) - fw.sum(l - 1);
    }
    for (int x : ans) cout << x << "\n";
    return 0;
}
