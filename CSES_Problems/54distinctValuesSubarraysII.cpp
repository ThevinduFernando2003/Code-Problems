#include <bits/stdc++.h>
using namespace std;

/*
CSES - Distinct Values Subarrays II

Count subarrays that contain at most k distinct values.

Pseudocode
----------
two pointers
expand right, add a[right] into a frequency map
while map size > k: remove a[left], left++
add (right-left+1) subarrays ending at right
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> freq;
    freq.reserve(n * 2);
    int l = 0;
    long long ans = 0;
    for (int r = 0; r < n; r++) {
        freq[a[r]]++;
        while ((int)freq.size() > k) {
            if (--freq[a[l]] == 0) freq.erase(a[l]);
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << "\n";
    return 0;
}
