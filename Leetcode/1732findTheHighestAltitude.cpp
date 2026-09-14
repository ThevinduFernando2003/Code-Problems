#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, best = 0;
        for (int g : gain) {
            alt += g;
            best = max(best, alt);
        }
        return best;
    }
};
