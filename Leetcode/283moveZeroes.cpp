#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        for (int x : nums) if (x != 0) nums[write++] = x;
        while (write < (int)nums.size()) nums[write++] = 0;
    }
};
