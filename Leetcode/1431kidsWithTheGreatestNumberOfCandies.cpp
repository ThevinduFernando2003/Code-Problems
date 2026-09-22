#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode 1431 - Kids With the Greatest Number of Candies

For each kid, report whether giving them extraCandies would make their
count at least as large as any other kid.

Pseudocode
----------
best := max(candies)
for each c in candies:
    answer[i] := (c + extraCandies >= best)
return answer
*/

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
