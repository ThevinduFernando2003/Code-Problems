#include <bits/stdc++.h>
using namespace std;

/*
CSES - Point Location Test

For each query, is point C left, right, or on AB?

Pseudocode
----------
cross := (B-A) x (C-A)
>0 LEFT, <0 RIGHT, 0 TOUCH
use 128-bit / long long; coords fit in 1e9 so 2e9*2e9 needs 64-bit carefully
(B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        long long cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        if (cross > 0) cout << "LEFT\n";
        else if (cross < 0) cout << "RIGHT\n";
        else cout << "TOUCH\n";
    }
    return 0;
}
