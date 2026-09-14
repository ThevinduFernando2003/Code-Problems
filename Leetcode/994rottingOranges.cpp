#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) ++fresh;
            }
        }
        if (fresh == 0) return 0;
        int minutes = 0;
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int sz = (int)q.size();
            bool grew = false;
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    --fresh;
                    grew = true;
                    q.push({nr, nc});
                }
            }
            if (grew) ++minutes;
        }
        return fresh == 0 ? minutes : -1;
    }
};
