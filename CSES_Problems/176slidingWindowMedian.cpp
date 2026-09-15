#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sliding Window Median

Lower median of each window of k.

Pseudocode
----------
two multisets: lo (max of smaller half), hi (min of larger half)
|lo| == |hi| or |lo| == |hi|+1
median := *lo.rbegin()
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> lo, hi;
    auto balance = [&]() {
        if (lo.size() > hi.size() + 1) {
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        } else if (hi.size() > lo.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    };
    auto add = [&](int x) {
        if (lo.empty() || x <= *lo.rbegin()) lo.insert(x);
        else hi.insert(x);
        balance();
    };
    auto del = [&](int x) {
        auto it = lo.find(x);
        if (it != lo.end()) lo.erase(it);
        else hi.erase(hi.find(x));
        balance();
    };
    for (int i = 0; i < n; i++) {
        add(a[i]);
        if (i >= k) del(a[i - k]);
        if (i >= k - 1) cout << *lo.rbegin() << " \n"[i == n - 1];
    }
    return 0;
}
