#include <bits/stdc++.h>
using namespace std;

/*
CSES - Counting Bits

How many 1-bits in binary representations of 1..n.

Pseudocode
----------
for each bit b, numbers with that bit set in 1..n:
    complete cycles of 2^(b+1) contribute 2^b ones each
    plus leftover in the current cycle
*/

long long count(long long n) {
    long long ans = 0;
    for (int b = 0; b < 60; b++) {
        long long len = 1LL << (b + 1);
        long long full = (n + 1) / len;
        ans += full * (1LL << b);
        long long rem = (n + 1) % len;
        ans += max(0LL, rem - (1LL << b));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    cout << count(n) << "\n";
    return 0;
}
