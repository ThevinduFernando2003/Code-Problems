#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
    bool dfs(const string& u, const string& dest, double prod,
             unordered_map<string, vector<pair<string, double>>>& g,
             unordered_set<string>& seen, double& ans) {
        if (u == dest) {
            ans = prod;
            return true;
        }
        seen.insert(u);
        for (auto& [v, w] : g[u]) {
            if (seen.count(v)) continue;
            if (dfs(v, dest, prod * w, g, seen, ans)) return true;
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                               vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0; i < (int)equations.size(); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            g[a].push_back({b, values[i]});
            g[b].push_back({a, 1.0 / values[i]});
        }
        vector<double> ans;
        for (auto& q : queries) {
            if (!g.count(q[0]) || !g.count(q[1])) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> seen;
            double val = -1.0;
            dfs(q[0], q[1], 1.0, g, seen, val);
            ans.push_back(val);
        }
        return ans;
    }
};
