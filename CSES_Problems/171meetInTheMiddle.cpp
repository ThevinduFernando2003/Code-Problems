#include <bits/stdc++.h>
using namespace std;

/*
CSES - Meet in the Middle

Number of subsets with sum x, n <= 40.

Pseudocode
----------
split into two halves
enumerate all subset sums of each half
for each sum s in left, add count of x-s in right
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int n1 = n / 2, n2 = n - n1;
    vector<long long> L, R;
    for (int m = 0; m < (1 << n1); m++) {
        long long s = 0;
        for (int i = 0; i < n1; i++) if (m >> i & 1) s += a[i];
        L.push_back(s);
    }
    for (int m = 0; m < (1 << n2); m++) {
        long long s = 0;
        for (int i = 0; i < n2; i++) if (m >> i & 1) s += a[n1 + i];
        R.push_back(s);
    }
    sort(R.begin(), R.end());
    long long ans = 0;
    for (long long s : L) {
        long long need = x - s;
        ans += upper_bound(R.begin(), R.end(), need) - lower_bound(R.begin(), R.end(), need);
    }
    cout << ans << "\n";
    return 0;
}
