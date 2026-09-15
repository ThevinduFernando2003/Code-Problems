#include <bits/stdc++.h>
using namespace std;

/*
CSES - Distributing Apples

n children, m identical apples: C(n+m-1, n-1) mod 1e9+7.

Pseudocode
----------
stars and bars
precompute fact up to n+m
C(n+m-1, m)
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
    int n, m;
    cin >> n >> m;
    int N = n + m;
    vector<long long> fact(N + 1), inv(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
    cout << fact[n + m - 1] * inv[m] % MOD * inv[n - 1] % MOD << "\n";
    return 0;
}
