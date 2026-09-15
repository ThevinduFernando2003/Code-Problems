#include <bits/stdc++.h>
using namespace std;

/*
CSES - Knight Moves Grid

Minimum knight moves from (1,1) to every cell of an n x n board.

Pseudocode
----------
BFS from (0,0) with the 8 knight deltas
print the distance grid
*/

int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    d[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n || d[ny][nx] != -1) continue;
            d[ny][nx] = d[y][x] + 1;
            q.push({ny, nx});
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cout << d[i][j] << " \n"[j + 1 == n];
    return 0;
}
