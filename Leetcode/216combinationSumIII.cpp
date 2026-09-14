#include <vector>
using namespace std;

class Solution {
    void dfs(int start, int k, int n, vector<int>& cur, vector<vector<int>>& ans) {
        if (k == 0 && n == 0) {
            ans.push_back(cur);
            return;
        }
        for (int x = start; x <= 9; ++x) {
            if (x > n) break;
            cur.push_back(x);
            dfs(x + 1, k - 1, n - x, cur, ans);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(1, k, n, cur, ans);
        return ans;
    }
};
