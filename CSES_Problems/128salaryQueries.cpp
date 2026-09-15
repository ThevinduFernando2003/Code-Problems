#include <bits/stdc++.h>
using namespace std;

/*
CSES - Salary Queries

Change one salary or count salaries in [a,b].

Pseudocode
----------
collect every salary that appears (initial, updates, query bounds)
compress to ranks
Fenwick counts how many employees have each rank
update: -1 old rank, +1 new rank
query: sum(rank(b)) - sum(rank(a)-1)
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
    vector<int> sal(n + 1);
    for (int i = 1; i <= n; i++) cin >> sal[i];
    struct Q {
        char t;
        int a, b;
    };
    vector<Q> qs(q);
    vector<int> vals;
    vals.reserve(n + 2 * q);
    for (int i = 1; i <= n; i++) vals.push_back(sal[i]);
    for (int i = 0; i < q; i++) {
        cin >> qs[i].t >> qs[i].a >> qs[i].b;
        if (qs[i].t == '!') vals.push_back(qs[i].b);
        else {
            vals.push_back(qs[i].a);
            vals.push_back(qs[i].b);
        }
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto id = [&](int x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };
    Fenwick fw((int)vals.size());
    for (int i = 1; i <= n; i++) fw.add(id(sal[i]), 1);
    for (auto& qu : qs) {
        if (qu.t == '!') {
            fw.add(id(sal[qu.a]), -1);
            sal[qu.a] = qu.b;
            fw.add(id(sal[qu.a]), 1);
        } else {
            cout << fw.sum(id(qu.b)) - fw.sum(id(qu.a) - 1) << "\n";
        }
    }
    return 0;
}
