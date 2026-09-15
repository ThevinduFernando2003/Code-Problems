#include <bits/stdc++.h>
using namespace std;

/*
CSES - Distinct Values Subsequences

Count nonempty subsequences whose values are all distinct. Order of
picking from the same positions follows the array order, so this is
the product over values of (frequency + 1) minus 1.

Pseudocode
----------
count frequency of each value
answer := 1
for each frequency f:
    answer := answer * (f + 1)  mod 1e9+7
print answer - 1
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MOD = 1e9 + 7;
    int n;
    cin >> n;
    unordered_map<int, int> freq;
    freq.reserve(n * 2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    long long ans = 1;
    for (auto [_, f] : freq) ans = ans * (f + 1) % MOD;
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}
