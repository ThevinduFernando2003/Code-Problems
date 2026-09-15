#include <bits/stdc++.h>
using namespace std;

/*
CSES - Knight's Tour

A path of a knight that visits every square of an 8x8 board once,
starting at a given square. Print the visit times.

Pseudocode
----------
Warnsdorff: always move to the unused square with the fewest onward moves
DFS with that ordering; backtrack if stuck
*/

int board[8][8];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool inside(int x, int y) { return x >= 0 && y >= 0 && x < 8 && y < 8; }

int degree(int x, int y) {
    int d = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (inside(nx, ny) && board[nx][ny] == 0) d++;
    }
    return d;
}

bool dfs(int x, int y, int step) {
    board[x][y] = step;
    if (step == 64) return true;
    vector<array<int, 3>> nxt;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (inside(nx, ny) && board[nx][ny] == 0) nxt.push_back({degree(nx, ny), nx, ny});
    }
    sort(nxt.begin(), nxt.end());
    for (auto [d, nx, ny] : nxt) if (dfs(nx, ny, step + 1)) return true;
    board[x][y] = 0;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    dfs(y - 1, x - 1, 1);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) cout << board[i][j] << " \n"[j == 7];
    }
    return 0;
}
