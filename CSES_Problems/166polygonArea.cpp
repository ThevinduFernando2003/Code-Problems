#include <bits/stdc++.h>
using namespace std;

/*
CSES - Polygon Area

Twice the area of a simple polygon (shoelace), integer.

Pseudocode
----------
sum := 0
for i: sum += x[i]*y[i+1] - x[i+1]*y[i]
print abs(sum)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    __int128 sum = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        sum += (__int128)x[i] * y[j] - (__int128)x[j] * y[i];
    }
    if (sum < 0) sum = -sum;
    cout << (long long)sum << "\n";
    return 0;
}
