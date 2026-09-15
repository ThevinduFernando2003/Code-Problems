#include <bits/stdc++.h>
using namespace std;

/*
CSES - Planets Queries I

Each planet has one outgoing teleporter. Answer q queries:
where you are after k teleports from planet x. k <= 1e18.

Pseudocode
----------
binary lifting
up[i][0] := next[i]
up[i][j] := up[ up[i][j-1] ][j-1]
to apply k, walk bits of k
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    const int LOG = 30;
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) cin >> up[0][i];
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n; i++) up[j][i] = up[j - 1][up[j - 1][i]];
    while (q--) {
        int x;
        long long k;
        cin >> x >> k;
        for (int j = 0; j < LOG; j++) if (k >> j & 1) x = up[j][x];
        cout << x << "\n";
    }
    return 0;
}
