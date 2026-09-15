#include <bits/stdc++.h>
using namespace std;

/*
CSES - Binomial Coefficients

q queries C(a,b) mod 1e9+7, a,b <= 1e6.

Pseudocode
----------
precompute fact[i] and invfact[i]
C(a,b) := 0 if b>a else fact[a] * invfact[b] * invfact[a-b]
*/

const long long MOD = 1e9 + 7;
const int N = 1000000;

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
    vector<long long> fact(N + 1), inv(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (b > a) cout << 0 << "\n";
        else cout << fact[a] * inv[b] % MOD * inv[a - b] % MOD << "\n";
    }
    return 0;
}
