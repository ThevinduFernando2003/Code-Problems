#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) if (i < (int)s.size() && c == s[i]) ++i;
        return i == (int)s.size();
    }
};
