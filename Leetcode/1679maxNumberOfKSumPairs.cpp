#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 1679 - Max Number of K-Sum Pairs

Count the maximum number of operations that remove two numbers summing
to k.

Pseudocode
----------
sort nums
i := 0, j := n - 1, ans := 0
while i < j:
    if nums[i] + nums[j] == k: ans := ans + 1, i := i + 1, j := j - 1
    else if sum < k: i := i + 1
    else: j := j - 1
return ans
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = (int)nums.size() - 1, ans = 0;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                ++ans;
                ++i;
                --j;
            } else if (sum < k) ++i;
            else --j;
        }
        return ans;
    }
};
