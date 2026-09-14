#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string prefix;
        auto it = products.begin();
        for (char c : searchWord) {
            prefix += c;
            it = lower_bound(it, products.end(), prefix);
            vector<string> row;
            for (auto p = it; p != products.end() && row.size() < 3 && p->compare(0, prefix.size(), prefix) == 0; ++p) {
                row.push_back(*p);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
