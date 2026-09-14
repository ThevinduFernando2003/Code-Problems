#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int keep = 0, end = INT_MIN;
        for (auto& iv : intervals) {
            if (iv[0] >= end) {
                ++keep;
                end = iv[1];
            }
        }
        return (int)intervals.size() - keep;
    }
};
