#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sliding Window Mex

Mex of each window of k. Mex is at most k.

Pseudocode
----------
count frequencies of values in 0..k
set of missing small values, or scan from 0
use freq[0..k] and a pointer / set of zeros
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> freq(k + 2);
    set<int> missing;
    for (int i = 0; i <= k + 1; i++) missing.insert(i);
    auto add = [&](int x) {
        if (x > k + 1) return;
        if (freq[x] == 0) missing.erase(x);
        freq[x]++;
    };
    auto del = [&](int x) {
        if (x > k + 1) return;
        freq[x]--;
        if (freq[x] == 0) missing.insert(x);
    };
    for (int i = 0; i < n; i++) {
        add(a[i]);
        if (i >= k) del(a[i - k]);
        if (i >= k - 1) cout << *missing.begin() << " \n"[i == n - 1];
    }
    return 0;
}
