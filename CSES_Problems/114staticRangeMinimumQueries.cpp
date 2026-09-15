#include <bits/stdc++.h>
using namespace std;

/*
CSES - Static Range Minimum Queries

Answer q range-minimum queries on a static array.

Pseudocode
----------
sparse table
st[i][0] := a[i]
st[i][j] := min(st[i][j-1], st[i+2^(j-1)][j-1])
query l r: k := floor(log2(r-l+1))
           min(st[l][k], st[r-2^k+1][k])
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int LOG = 1;
    while ((1 << LOG) <= n) LOG++;
    vector<vector<int>> st(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) cin >> st[0][i];
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int k = 31 - __builtin_clz(r - l + 1);
        cout << min(st[k][l], st[k][r - (1 << k) + 1]) << "\n";
    }
    return 0;
}
