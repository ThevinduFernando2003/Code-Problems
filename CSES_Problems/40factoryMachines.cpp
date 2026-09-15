#include <bits/stdc++.h>
using namespace std;

/*
CSES - Factory Machines

n machines make one product every t_i time units. Minimum time to make k products.

Pseudocode
----------
binary search the time T
a machine produces T / t_i products in time T
if total products >= k, try a smaller T
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    long long lo = 1, hi = *min_element(t.begin(), t.end()) * k, ans = hi;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long made = 0;
        for (long long x : t) {
            made += mid / x;
            if (made >= k) break;
        }
        if (made >= k) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}
