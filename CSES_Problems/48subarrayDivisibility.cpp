#include <bits/stdc++.h>
using namespace std;

/*
CSES - Subarray Divisibility

Count subarrays whose sum is divisible by n.

Pseudocode
----------
prefix modulo n
freq[0] := 1
for each value:
    prefix := ((prefix + v) % n + n) % n
    answer += freq[prefix]
    freq[prefix]++
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> freq(n);
    freq[0] = 1;
    long long prefix = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        prefix = ((prefix + v) % n + n) % n;
        ans += freq[prefix];
        freq[prefix]++;
    }
    cout << ans << "\n";
    return 0;
}
