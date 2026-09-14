#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        int a = 0, b = 0;
        for (int i = 2; i <= n; ++i) {
            int cur = min(b + cost[i - 1], a + cost[i - 2]);
            a = b;
            b = cur;
        }
        return b;
    }
};
