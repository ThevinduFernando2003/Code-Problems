#include <bits/stdc++.h>
using namespace std;

/*
CSES - Another Game

Each move: pick any nonempty subset of heaps and remove one coin from each.
The player who takes the last coin wins.

Pseudocode
----------
first wins iff the largest heap is odd
(pairing strategy on even maxima)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mx = 0;
        while (n--) {
            int x;
            cin >> x;
            mx = max(mx, x);
        }
        cout << (mx % 2 ? "first\n" : "second\n");
    }
    return 0;
}
