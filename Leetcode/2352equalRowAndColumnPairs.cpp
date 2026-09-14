#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        map<vector<int>, int> rows;
        for (auto& row : grid) ++rows[row];
        int ans = 0;
        for (int c = 0; c < n; ++c) {
            vector<int> col(n);
            for (int r = 0; r < n; ++r) col[r] = grid[r][c];
            ans += rows[col];
        }
        return ans;
    }
};
