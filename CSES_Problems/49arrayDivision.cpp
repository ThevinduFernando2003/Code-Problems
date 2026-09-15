#include <bits/stdc++.h>
using namespace std;

/*
CSES - Array Division

Split the array into exactly k contiguous parts. Minimize the maximum part sum.

Pseudocode
----------
binary search the maximum allowed sum M
greedy: walk left to right, start a new part whenever adding the next
value would exceed M
need at most k parts
*/

bool ok(const vector<long long>& a, int k, long long M) {
    int used = 1;
    long long cur = 0;
    for (long long x : a) {
        if (x > M) return false;
        if (cur + x > M) {
            used++;
            cur = x;
            if (used > k) return false;
        } else cur += x;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lo = max(lo, a[i]);
        hi += a[i];
    }
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (ok(a, k, mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    return 0;
}
