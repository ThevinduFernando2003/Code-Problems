#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    static vector<int> onlyIn(const vector<int>& a, const unordered_set<int>& other) {
        unordered_set<int> seen;
        vector<int> ans;
        for (int x : a) {
            if (!other.count(x) && seen.insert(x).second) ans.push_back(x);
        }
        return ans;
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a(nums1.begin(), nums1.end()), b(nums2.begin(), nums2.end());
        return {onlyIn(nums1, b), onlyIn(nums2, a)};
    }
};
