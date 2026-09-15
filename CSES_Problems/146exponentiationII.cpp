#include <bits/stdc++.h>
using namespace std;

/*
CSES - Exponentiation II

Compute a^(b^c) mod 1e9+7.

Pseudocode
----------
phi(1e9+7) = 1e9+6
a^e mod p = a^(e mod phi) when gcd(a,p)=1
always use a^(b^c mod phi) but if b^c >= phi and a%p==0 handle 0
CSES trick: modpow(a, modpow(b,c, MOD-1), MOD) works for this prime
including a=0, b=0 cases via 0^0 := 1 in the inner pow
*/

const long long MOD = 1e9 + 7;

long long modpow(long long a, long long b, long long m) {
    long long r = 1 % m;
    a %= m;
    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
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
        long long a, b, c;
        cin >> a >> b >> c;
        if (a % MOD == 0) {
            if (b == 0) cout << (c == 0 ? 0 : 1) << "\n";
            else cout << 0 << "\n";
        } else {
            cout << modpow(a, modpow(b, c, MOD - 1), MOD) << "\n";
        }
    }
    return 0;
}
