#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sum of Three Values

Find three distinct indices whose values sum to x.

Pseudocode
----------
store (value, original index) and sort by value
for i from 1 to n:
    two pointers on the subarray after i
    while left < right:
        if a[i]+a[left]+a[right] == x: print indices
        if sum < x: left++
        else right--
print IMPOSSIBLE
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            long long s = a[i].first + a[l].first + a[r].first;
            if (s == x) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            }
            if (s < x) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
