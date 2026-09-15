#include <bits/stdc++.h>
using namespace std;

/*
CSES - Distinct Values Subarrays

Count subarrays in which every value appears at most once.

Pseudocode
----------
two pointers
right expands, last[a[right]] = right
if a[right] was already inside the window, move left to last+1
every window [left, right] contributes (right-left+1) new subarrays ending at right
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> last;
    last.reserve(n * 2);
    int l = 0;
    long long ans = 0;
    for (int r = 0; r < n; r++) {
        if (last.count(a[r]) && last[a[r]] >= l) l = last[a[r]] + 1;
        last[a[r]] = r;
        ans += r - l + 1;
    }
    cout << ans << "\n";
    return 0;
}
