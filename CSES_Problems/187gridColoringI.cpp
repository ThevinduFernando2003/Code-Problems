#include <bits/stdc++.h>
using namespace std;

/*
CSES - Grid Coloring I

Change every cell to a different A-D letter so 4-adjacent cells differ.

Pseudocode
----------
4 colors, at most 3 forbidden: old letter, left, up
always pick the first A-D not in that set
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char old = g[i][j];
            for (char c = 'A'; c <= 'D'; c++) {
                if (c == old) continue;
                if (i && g[i - 1][j] == c) continue;
                if (j && g[i][j - 1] == c) continue;
                g[i][j] = c;
                break;
            }
        }
    }
    for (auto& s : g) cout << s << "\n";
    return 0;
}
