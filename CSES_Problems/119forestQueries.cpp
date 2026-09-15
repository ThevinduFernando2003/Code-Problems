#include <bits/stdc++.h>
using namespace std;

/*
CSES - Forest Queries

q queries: how many trees in the axis-aligned rectangle [y1,x1]..[y2,x2].

Pseudocode
----------
2D prefix sums
p[i][j] := trees in [1,1]..[i,j]
query := p[y2][x2] - p[y1-1][x2] - p[y2][x1-1] + p[y1-1][x1-1]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> p(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (s[j - 1] == '*');
        }
    }
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << p[y2][x2] - p[y1 - 1][x2] - p[y2][x1 - 1] + p[y1 - 1][x1 - 1] << "\n";
    }
    return 0;
}
