#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = (int)potions.size();
        vector<int> ans;
        ans.reserve(spells.size());
        for (int spell : spells) {
            long long need = (success + spell - 1LL) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), need,
                                 [](int potion, long long req) { return potion < req; });
            ans.push_back(m - (int)(it - potions.begin()));
        }
        return ans;
    }
};
