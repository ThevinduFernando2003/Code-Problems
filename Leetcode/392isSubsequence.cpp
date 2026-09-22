#include <string>
using namespace std;

/*
LeetCode 392 - Is Subsequence

Return true if s can be formed by deleting some (or no) characters
from t without changing the order of the remaining characters.

Pseudocode
----------
i := 0
for each character c in t:
    if i < |s| and c == s[i]: i := i + 1
return i == |s|
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) if (i < (int)s.size() && c == s[i]) ++i;
        return i == (int)s.size();
    }
};
