#include <bits/stdc++.h>
using namespace std;

/*
CSES - Subarray Sums II

Count subarrays that sum to x. Values may be negative.

Pseudocode
----------
prefix := 0
map[0] := 1
for each value v:
    prefix := prefix + v
    answer += map[prefix - x]
    map[prefix]++
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;
    unordered_map<long long, int> freq;
    freq.reserve(n * 2);
    freq[0] = 1;
    long long prefix = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        prefix += v;
        auto it = freq.find(prefix - x);
        if (it != freq.end()) ans += it->second;
        freq[prefix]++;
    }
    cout << ans << "\n";
    return 0;
}
