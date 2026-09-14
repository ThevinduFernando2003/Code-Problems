#include <vector>
#include <string>
using namespace std;

class Solution {
    const vector<string> keys{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(const string& digits, int i, string& cur, vector<string>& ans) {
        if (i == (int)digits.size()) {
            ans.push_back(cur);
            return;
        }
        for (char c : keys[digits[i] - '0']) {
            cur.push_back(c);
            dfs(digits, i + 1, cur, ans);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        string cur;
        dfs(digits, 0, cur, ans);
        return ans;
    }
};
