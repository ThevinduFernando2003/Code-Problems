#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 643 - Maximum Average Subarray I

Return the maximum average of any contiguous subarray of length k.

Pseudocode
----------
window := sum of first k elements
best := window
for i from k to n-1:
    window := window + nums[i] - nums[i - k]
    best := max(best, window)
return best / k
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long window = 0;
        for (int i = 0; i < k; ++i) window += nums[i];
        long long best = window;
        for (int i = k; i < (int)nums.size(); ++i) {
            window += nums[i] - nums[i - k];
            best = max(best, window);
        }
        return (double)best / k;
    }
};
