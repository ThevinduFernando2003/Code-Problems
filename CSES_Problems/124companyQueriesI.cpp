#include <bits/stdc++.h>
using namespace std;

/*
CSES - Company Queries I

Direct boss of employee x after k steps, or -1.

Pseudocode
----------
binary lifting on parent pointers
up[i][0] := boss of i
jump k bits, if we pass the root print -1
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    const int LOG = 19;
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int i = 2; i <= n; i++) cin >> up[0][i];
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n; i++) up[j][i] = up[j - 1][up[j - 1][i]];
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < LOG; j++) if (k >> j & 1) x = up[j][x];
        cout << (x ? x : -1) << "\n";
    }
    return 0;
}
