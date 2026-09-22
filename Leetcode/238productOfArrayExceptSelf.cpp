#include <vector>
using namespace std;

/*
LeetCode 238 - Product of Array Except Self

Return an array where answer[i] is the product of all nums values
except nums[i]. Do not use division.

Pseudocode
----------
left := 1
for i from 0 to n-1:
    answer[i] := left
    left := left * nums[i]
right := 1
for i from n-1 down to 0:
    answer[i] := answer[i] * right
    right := right * nums[i]
return answer
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n, 1);
        int left = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
