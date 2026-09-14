#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = (int)nums1.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) pairs[i] = {nums2[i], nums1[i]};
        sort(pairs.rbegin(), pairs.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, best = 0;
        for (auto [min2, val1] : pairs) {
            pq.push(val1);
            sum += val1;
            if ((int)pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() == k) best = max(best, sum * (long long)min2);
        }
        return best;
    }
};
