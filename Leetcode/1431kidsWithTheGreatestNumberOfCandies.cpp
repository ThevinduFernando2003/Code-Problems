#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int best = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        ans.reserve(candies.size());
        for (int c : candies) ans.push_back(c + extraCandies >= best);
        return ans;
    }
};
