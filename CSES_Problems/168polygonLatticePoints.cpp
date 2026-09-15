#include <bits/stdc++.h>
using namespace std;

/*
CSES - Polygon Lattice Points

Count interior and boundary lattice points of a simple polygon.

Pseudocode
----------
boundary: gcd(|dx|,|dy|) on each edge, sum (gcd - 0 for vertex double-count: each edge contributes gcd)
Pick: Area = I + B/2 - 1  =>  I = Area - B/2 + 1
twice-area from shoelace, I = (2A - B + 2) / 2
*/

long long g(long long a, long long b) { return gcd(abs(a), abs(b)); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    __int128 area2 = 0;
    long long B = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area2 += (__int128)x[i] * y[j] - (__int128)x[j] * y[i];
        B += g(x[j] - x[i], y[j] - y[i]);
    }
    if (area2 < 0) area2 = -area2;
    long long I = (long long)((area2 - B + 2) / 2);
    cout << I << " " << B << "\n";
    return 0;
}
