#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int arrows = 0;
        long long end = LLONG_MIN;
        for (auto& p : points) {
            if (p[0] > end) {
                ++arrows;
                end = p[1];
            }
        }
        return arrows;
    }
};
