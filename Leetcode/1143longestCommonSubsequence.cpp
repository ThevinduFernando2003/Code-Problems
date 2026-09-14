#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = (int)text2.size();
        vector<int> prev(n + 1), cur(n + 1);
        for (char a : text1) {
            for (int j = 1; j <= n; ++j) {
                if (a == text2[j - 1]) cur[j] = prev[j - 1] + 1;
                else cur[j] = max(prev[j], cur[j - 1]);
            }
            prev.swap(cur);
        }
        return prev[n];
    }
};
