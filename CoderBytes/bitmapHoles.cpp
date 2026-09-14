#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Bitmap Holes

strArr is a bitmap of '0' and '1' rows. A hole is a 4-connected group
of zeros. Return how many holes there are.

Examples:
  {"10111", "10101", "11101", "11111"} -> 2
  {"01111", "01101", "00011", "11110"} -> 3

Pseudocode
----------
function BitmapHoles(grid):
    holes := 0
    for each cell (r, c) that is '0' and not visited:
        holes := holes + 1
        flood-fill all 4-adjacent zeros
    return holes
*/

int BitmapHoles(vector<string> grid) {
    int m = (int)grid.size(), n = (int)grid[0].size(), holes = 0;
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] != '0') continue;
            ++holes;
            queue<pair<int, int>> q;
            q.push({r, c});
            grid[r][c] = '1';
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nr = x + dr[k], nc = y + dc[k];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != '0') continue;
                    grid[nr][nc] = '1';
                    q.push({nr, nc});
                }
            }
        }
    }
    return holes;
}

int main() {
    int m;
    cin >> m;
    vector<string> grid(m);
    for (int i = 0; i < m; ++i) cin >> grid[i];
    cout << BitmapHoles(grid) << endl;
    return 0;
}
