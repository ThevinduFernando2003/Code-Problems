#include <bits/stdc++.h>
using namespace std;

/*
CSES - Prime Multiples

Count numbers in 1..n divisible by at least one of k primes (inclusion-exclusion).

Pseudocode
----------
for each nonempty subset S of the k primes:
    p := product (stop if p > n)
    add or subtract n/p according to |S| parity
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    int k;
    cin >> n >> k;
    vector<long long> p(k);
    for (int i = 0; i < k; i++) cin >> p[i];
    long long ans = 0;
    for (int m = 1; m < (1 << k); m++) {
        __int128 prod = 1;
        int bits = 0;
        bool ov = false;
        for (int i = 0; i < k; i++) if (m >> i & 1) {
            bits++;
            prod *= p[i];
            if (prod > n) {
                ov = true;
                break;
            }
        }
        if (ov) continue;
        long long cnt = n / (long long)prod;
        if (bits & 1) ans += cnt;
        else ans -= cnt;
    }
    cout << ans << "\n";
    return 0;
}
