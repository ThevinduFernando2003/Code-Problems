#include <vector>
#include <numeric>
using namespace std;

/*
LeetCode 724 - Find Pivot Index

Return the leftmost index where the sum of values to the left equals
the sum of values to the right. Return -1 if none exists.

Pseudocode
----------
total := sum(nums)
left := 0
for i from 0 to n-1:
    if left == total - left - nums[i]: return i
    left := left + nums[i]
return -1
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (left == total - left - nums[i]) return i;
            left += nums[i];
        }
        return -1;
    }
};
