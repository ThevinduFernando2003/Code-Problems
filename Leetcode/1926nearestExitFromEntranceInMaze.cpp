#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = (int)maze.size(), n = (int)maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int sz = (int)q.size();
            ++steps;
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n || maze[nr][nc] == '+') continue;
                    if (nr == 0 || nc == 0 || nr == m - 1 || nc == n - 1) return steps;
                    maze[nr][nc] = '+';
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};
