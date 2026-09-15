#include <bits/stdc++.h>
using namespace std;

/*
CSES - Nim Game I

Standard Nim: first player wins iff xor of heap sizes is nonzero.

Pseudocode
----------
x := xor of all heaps
print FIRST if x else SECOND
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
            x ^= y;
        }
        cout << (x ? "first\n" : "second\n");
    }
    return 0;
}
