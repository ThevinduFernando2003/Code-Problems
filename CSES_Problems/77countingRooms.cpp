#include <bits/stdc++.h>
using namespace std;

/*
CSES - Counting Rooms

A room is a 4-connected component of floor cells '.' . Walls are '#'.

Pseudocode
----------
rooms := 0
for each cell (i, j) that is '.':
    rooms++
    flood-fill that component (DFS/BFS), marking visited as '#'
print rooms
*/

int n, m;
vector<string> grid;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    grid[x][y] = '#';
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                rooms++;
                dfs(i, j);
            }
        }
    }
    cout << rooms << "\n";
    return 0;
}
