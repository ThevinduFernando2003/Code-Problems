#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = (int)costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;
        int i = 0, j = n - 1;
        for (int t = 0; t < candidates && i <= j; ++t) left.push(costs[i++]);
        for (int t = 0; t < candidates && i <= j; ++t) right.push(costs[j--]);
        long long ans = 0;
        while (k--) {
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                ans += left.top();
                left.pop();
                if (i <= j) left.push(costs[i++]);
            } else {
                ans += right.top();
                right.pop();
                if (i <= j) right.push(costs[j--]);
            }
        }
        return ans;
    }
};
