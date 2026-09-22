#include <vector>
#include <climits>
using namespace std;

/*
LeetCode 334 - Increasing Triplet Subsequence

Return true if there exist i < j < k with nums[i] < nums[j] < nums[k].

Pseudocode
----------
first := +inf, second := +inf
for each x in nums:
    if x <= first: first := x
    else if x <= second: second := x
    else: return true   // x > first and x > second
return false
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int x : nums) {
            if (x <= first) first = x;
            else if (x <= second) second = x;
            else return true;
        }
        return false;
    }
};
