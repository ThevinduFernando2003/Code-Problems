#include <bits/stdc++.h>
using namespace std;

/*
CSES - Hamming Distance

Minimum Hamming distance among n bit-strings of length k <= 30.

Pseudocode
----------
parse each string as an integer
for all pairs, min popcount(a xor b)
n <= 2e4 so O(n^2) bit operations
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int v = 0;
        for (char c : s) v = v * 2 + (c - '0');
        a[i] = v;
    }
    int ans = k;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
    cout << ans << "\n";
    return 0;
}
