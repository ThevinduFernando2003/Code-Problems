#include <bits/stdc++.h>
using namespace std;

/*
CSES - Nim Game II

Remove 1, 2, or 3 from a single heap. Grundy(n) = n mod 4.

Pseudocode
----------
xor all (heap % 4)
FIRST if nonzero
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = 0;
        while (n--) {
            int y;
            cin >> y;
            x ^= y % 4;
        }
        cout << (x ? "first\n" : "second\n");
    }
    return 0;
}
