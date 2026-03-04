#include <bits/stdc++.h>
using namespace std;

const int N = 7;
bool visited[N][N];
string path;
int answer = 0;

// Directions: down, up, left, right
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'D', 'U', 'L', 'R'};

void dfs(int x, int y, int step) {
    // If we reached (6,0) before the end of path, invalid
    if (x == 6 && y == 0) {
        if (step == 48) answer++;
        return;
    }
    
    // If path finished but not at (6,0), invalid
    if (step >= 48) return;
    
    // Prune dead ends: if we're boxed in (cannot move in any direction)
    if ((x == 0 || visited[x-1][y]) && (x == 6 || visited[x+1][y]) &&
        (y == 0 || visited[x][y-1]) && (y == 6 || visited[x][y+1])) {
        return;
    }
    
    char move = path[step];
    for (int d = 0; d < 4; d++) {
        if (move != '?' && move != dir[d]) continue;
        
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if (nx < 0 || nx >= 7 || ny < 0 || ny >= 7) continue; // boundary check
        if (visited[nx][ny]) continue; // already visited
        
        visited[nx][ny] = true;
        dfs(nx, ny, step + 1);
        visited[nx][ny] = false;
    }
}

int main() {
    cin >> path;
    
    // Initialize starting point (0,0)
    visited[0][0] = true;
    dfs(0, 0, 0);
    
    cout << answer << endl;
    return 0;
}