#include <string>
using namespace std;

/*
LeetCode 1768 - Merge Strings Alternately

Build a string by taking one character from word1, then one from word2,
repeating until both inputs are exhausted.

Pseudocode
----------
i := 0, j := 0, ans := empty
while i < |word1| or j < |word2|:
    if i < |word1|: append word1[i], i := i + 1
    if j < |word2|: append word2[j], j := j + 1
return ans
*/

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
