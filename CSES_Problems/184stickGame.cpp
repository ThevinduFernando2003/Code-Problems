#include <bits/stdc++.h>
using namespace std;

/*
CSES - Stick Game

n sticks, moves from a given set. Who wins with optimal play?

Pseudocode
----------
win[0] := false
win[i] := true if some move m <= i has !win[i-m]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> mv(k);
    for (int i = 0; i < k; i++) cin >> mv[i];
    vector<char> win(n + 1);
    string ans(n, 'L');
    for (int i = 1; i <= n; i++) {
        for (int m : mv) if (m <= i && !win[i - m]) {
            win[i] = 1;
            break;
        }
        ans[i - 1] = win[i] ? 'W' : 'L';
    }
    cout << ans << "\n";
    return 0;
}
