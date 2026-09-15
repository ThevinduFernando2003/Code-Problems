#include <bits/stdc++.h>
using namespace std;

/*
CSES - List Removals

Remove the p-th remaining element n times.

Pseudocode
----------
Fenwick of 1s, one per position still present
k-th remaining: binary search smallest i with fenwick.sum(i) == k
print a[i], add -1 at i
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
    int kth(int k) {
        int i = 0;
        for (int p = 1 << 18; p; p >>= 1)
            if (i + p <= n && bit[i + p] < k) {
                i += p;
                k -= bit[i];
            }
        return i + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fw.add(i, 1);
    }
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        int idx = fw.kth(p);
        cout << a[idx] << " \n"[i + 1 == n];
        fw.add(idx, -1);
    }
    return 0;
}
