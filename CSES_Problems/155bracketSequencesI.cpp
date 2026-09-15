#include <bits/stdc++.h>
using namespace std;

/*
CSES - Bracket Sequences I

Number of valid bracket strings of length n (Catalan), mod 1e9+7.

Pseudocode
----------
if n odd: 0
else Catalan(n/2) = C(n, n/2) / (n/2 + 1)
*/

const long long MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << "\n";
        return 0;
    }
    int k = n / 2;
    vector<long long> fact(n + 1), inv(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
    long long c = fact[n] * inv[k] % MOD * inv[n - k] % MOD;
    cout << c * modpow(k + 1, MOD - 2) % MOD << "\n";
    return 0;
}
