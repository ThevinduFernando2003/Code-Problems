#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sum of Divisors

sum_{i=1..n} sigma(i)  where sigma is the sum of divisors, mod 1e9+7.

Pseudocode
----------
for each possible quotient q, numbers i with n/i = q form a segment [l,r]
they contribute q * (l+...+r)
sum 1..k = k*(k+1)/2
iterate l := 1; r := n/(n/l)
*/

const long long MOD = 1e9 + 7;
const long long INV2 = 500000004;

long long rangeSum(long long l, long long r) {
    auto s = [&](long long k) { return k % MOD * ((k + 1) % MOD) % MOD * INV2 % MOD; };
    long long x = s(r) - s(l - 1);
    if (x < 0) x += MOD;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long l = 1; l <= n;) {
        long long q = n / l;
        long long r = n / q;
        ans = (ans + q % MOD * rangeSum(l, r)) % MOD;
        l = r + 1;
    }
    cout << ans << "\n";
    return 0;
}
