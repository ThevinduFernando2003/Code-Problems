#include <vector>
using namespace std;

/*
LeetCode 283 - Move Zeroes

Move all zeroes to the end of the array while keeping the relative
order of the non-zero values. Do it in place.

Pseudocode
----------
write := 0
for each x in nums:
    if x != 0: nums[write] := x, write := write + 1
fill nums[write .. end] with 0
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        for (int x : nums) if (x != 0) nums[write++] = x;
        while (write < (int)nums.size()) nums[write++] = 0;
    }
};
