#include <bits/stdc++.h>
using namespace std;

/*
CSES - Exponentiation

Compute a^b mod 1e9+7.

Pseudocode
----------
binary exponentiation
if b is odd: ans := ans * a
a := a*a, b := b/2
*/

const long long MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
    long long r = 1 % MOD;
    a %= MOD;
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
    while (n--) {
        long long a, b;
        cin >> a >> b;
        cout << modpow(a, b) << "\n";
    }
    return 0;
}
