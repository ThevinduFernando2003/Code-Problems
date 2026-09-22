#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 11 - Container With Most Water

Choose two vertical lines so the axis-aligned container they form
holds the most water.

Pseudocode
----------
i := 0, j := n - 1, best := 0
while i < j:
    best := max(best, min(height[i], height[j]) * (j - i))
    if height[i] < height[j]: i := i + 1
    else: j := j - 1
return best
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = (int)height.size() - 1, best = 0;
        while (i < j) {
            best = max(best, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) ++i;
            else --j;
        }
        return best;
    }
};
