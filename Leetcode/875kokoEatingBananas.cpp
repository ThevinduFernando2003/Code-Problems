#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    static bool ok(const vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for (int p : piles) hours += (p + (long long)speed - 1) / speed;
        return hours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(piles, h, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
