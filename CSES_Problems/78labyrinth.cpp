#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    pair<int, int> start = {-1, -1}, goal = {-1, -1};

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            } else if (grid[i][j] == 'B') {
                goal = {i, j};
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;

    q.push(start);
    dist[start.first][start.second] = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char move[4] = {'D', 'U', 'R', 'L'};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (make_pair(x, y) == goal) {
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') {
                continue;
            }
            if (dist[nx][ny] != -1) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            parent[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }

    if (dist[goal.first][goal.second] == -1) {
        cout << "NO" << endl;
        return 0;
    }

    string path;
    pair<int, int> current = goal;

    while (current != start) {
        auto [px, py] = parent[current.first][current.second];

        if (px == current.first + 1) {
            path.push_back('U');
        } else if (px == current.first - 1) {
            path.push_back('D');
        } else if (py == current.second + 1) {
            path.push_back('L');
        } else {
            path.push_back('R');
        }

        current = {px, py};
    }

    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << dist[goal.first][goal.second] << endl;
    cout << path << endl;

    return 0;
}
