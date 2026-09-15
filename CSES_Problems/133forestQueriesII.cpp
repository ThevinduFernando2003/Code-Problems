#include <bits/stdc++.h>
using namespace std;

/*
CSES - Forest Queries II

Toggle a tree and answer 2D rectangle counts.

Pseudocode
----------
2D Fenwick
toggle (y,x): add +1 or -1 at (y,x)
query: prefix(y2,x2)-prefix(y1-1,x2)-prefix(y2,x1-1)+prefix(y1-1,x1-1)
*/

int n;
vector<vector<int>> bit;

void add(int y, int x, int v) {
    for (int i = y; i <= n; i += i & -i)
        for (int j = x; j <= n; j += j & -j) bit[i][j] += v;
}

int sum(int y, int x) {
    int s = 0;
    for (int i = y; i > 0; i -= i & -i)
        for (int j = x; j > 0; j -= j & -j) s += bit[i][j];
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    vector<string> g(n + 1);
    bit.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        g[i] = " " + s;
        for (int j = 1; j <= n; j++)
            if (g[i][j] == '*') add(i, j, 1);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int y, x;
            cin >> y >> x;
            int d = (g[y][x] == '*') ? -1 : 1;
            g[y][x] = (g[y][x] == '*') ? '.' : '*';
            add(y, x, d);
        } else {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << sum(y2, x2) - sum(y1 - 1, x2) - sum(y2, x1 - 1) + sum(y1 - 1, x1 - 1) << "\n";
        }
    }
    return 0;
}
