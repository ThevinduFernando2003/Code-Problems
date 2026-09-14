#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : connections) {
            g[e[0]].push_back({e[1], 1});
            g[e[1]].push_back({e[0], 0});
        }
        int ans = 0;
        vector<int> seen(n);
        auto dfs = [&](auto&& dfs, int u) -> void {
            seen[u] = 1;
            for (auto [v, cost] : g[u]) {
                if (!seen[v]) {
                    ans += cost;
                    dfs(dfs, v);
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
