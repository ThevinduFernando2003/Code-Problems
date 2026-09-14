#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int skip = 0, take = 0;
        for (int x : nums) {
            int nextTake = skip + x;
            skip = max(skip, take);
            take = nextTake;
        }
        return max(skip, take);
    }
};
