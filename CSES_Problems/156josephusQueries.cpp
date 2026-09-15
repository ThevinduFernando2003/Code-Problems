#include <bits/stdc++.h>
using namespace std;

/*
CSES - Josephus Queries

Every second child is removed. Who is the k-th removed (1-indexed)?

Pseudocode
----------
first half of removals are the even positions: 2,4,6,...
if k <= n/2 (with the odd-n extra case for removing 1):
    map directly to 2k, wrapping to 1 when n is odd
else recurse on the remaining n/2 people and map odds back
*/

long long solve(long long n, long long k) {
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) {
        if (2 * k > n) return (2 * k) % n;
        return 2 * k;
    }
    long long x = solve(n / 2, k - (n + 1) / 2);
    if (n & 1) return 2 * x + 1;
    return 2 * x - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        long long n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}
