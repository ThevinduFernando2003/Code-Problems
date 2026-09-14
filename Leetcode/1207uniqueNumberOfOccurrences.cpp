#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) ++freq[x];
        unordered_set<int> seen;
        for (const auto& p : freq) if (!seen.insert(p.second).second) return false;
        return true;
    }
};
