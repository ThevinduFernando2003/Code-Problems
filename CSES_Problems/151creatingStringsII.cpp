#include <bits/stdc++.h>
using namespace std;

/*
CSES - Creating Strings II

Number of distinct permutations of a string, mod 1e9+7.

Pseudocode
----------
n! / (c_a! * c_b! * ... * c_z!)
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
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<long long> fact(n + 1), inv(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
    int cnt[26] = {};
    for (char c : s) cnt[c - 'a']++;
    long long ans = fact[n];
    for (int i = 0; i < 26; i++) ans = ans * inv[cnt[i]] % MOD;
    cout << ans << "\n";
    return 0;
}
