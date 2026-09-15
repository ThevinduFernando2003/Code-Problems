#include <bits/stdc++.h>
using namespace std;

/*
CSES - Multiplication Table

Median of the n x n multiplication table, n odd.

Pseudocode
----------
binary search v
count how many products i*j <= v: for each row i, min(n, v/i)
need at least (n*n+1)/2 values <= v
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    long long need = (n * n + 1) / 2;
    long long lo = 1, hi = n * n, ans = 1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long cnt = 0;
        for (long long i = 1; i <= n; i++) cnt += min(n, mid / i);
        if (cnt >= need) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}
