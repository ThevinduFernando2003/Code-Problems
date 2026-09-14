#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        ans.reserve(word1.size() + word2.size());
        int i = 0, j = 0;
        while (i < (int)word1.size() || j < (int)word2.size()) {
            if (i < (int)word1.size()) ans += word1[i++];
            if (j < (int)word2.size()) ans += word2[j++];
        }
        return ans;
    }
};
