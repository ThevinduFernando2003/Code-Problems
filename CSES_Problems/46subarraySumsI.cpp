#include <bits/stdc++.h>
using namespace std;

/*
CSES - Subarray Sums I

Count subarrays that sum to x. All values are positive.

Pseudocode
----------
two pointers / sliding window
right expands, add a[right]
while window sum > x: subtract a[left], left++
if sum == x: answer++
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0;
    long long sum = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > x) sum -= a[l++];
        if (sum == x) ans++;
    }
    cout << ans << "\n";
    return 0;
}
