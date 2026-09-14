#include <vector>
using namespace std;

class Solution {
    void dfs(int u, vector<vector<int>>& g, vector<int>& seen) {
        seen[u] = 1;
        for (int v = 0; v < (int)g.size(); ++v) {
            if (g[u][v] && !seen[v]) dfs(v, g, seen);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size(), ans = 0;
        vector<int> seen(n);
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                ++ans;
                dfs(i, isConnected, seen);
            }
        }
        return ans;
    }
};
