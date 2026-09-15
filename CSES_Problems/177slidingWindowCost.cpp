#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sliding Window Cost

Min cost to equalize a window = sum |a[i] - median|.

Pseudocode
----------
same two-multiset median as Sliding Window Median
track sumLo, sumHi
cost = median*|lo| - sumLo + sumHi - median*|hi|
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> lo, hi;
    long long sumLo = 0, sumHi = 0;
    auto balance = [&]() {
        if ((int)lo.size() > (int)hi.size() + 1) {
            int x = *lo.rbegin();
            lo.erase(prev(lo.end()));
            sumLo -= x;
            hi.insert(x);
            sumHi += x;
        } else if (hi.size() > lo.size()) {
            int x = *hi.begin();
            hi.erase(hi.begin());
            sumHi -= x;
            lo.insert(x);
            sumLo += x;
        }
    };
    auto add = [&](int x) {
        if (lo.empty() || x <= *lo.rbegin()) {
            lo.insert(x);
            sumLo += x;
        } else {
            hi.insert(x);
            sumHi += x;
        }
        balance();
    };
    auto del = [&](int x) {
        auto it = lo.find(x);
        if (it != lo.end()) {
            lo.erase(it);
            sumLo -= x;
        } else {
            hi.erase(hi.find(x));
            sumHi -= x;
        }
        balance();
    };
    for (int i = 0; i < n; i++) {
        add(a[i]);
        if (i >= k) del(a[i - k]);
        if (i >= k - 1) {
            long long m = *lo.rbegin();
            long long cost = m * (long long)lo.size() - sumLo + sumHi - m * (long long)hi.size();
            cout << cost << " \n"[i == n - 1];
        }
    }
    return 0;
}
