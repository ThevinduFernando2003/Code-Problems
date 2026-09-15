#include <bits/stdc++.h>
using namespace std;

/*
CSES - Christmas Party

Derangements of n people, mod 1e9+7.

Pseudocode
----------
d[0]=1, d[1]=0
d[i] = (i-1) * (d[i-1] + d[i-2])
*/

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    long long a = 1, b = 0;
    for (int i = 2; i <= n; i++) {
        long long c = (i - 1) * ((a + b) % MOD) % MOD;
        a = b;
        b = c;
    }
    cout << b << "\n";
    return 0;
}
