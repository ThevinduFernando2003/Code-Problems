#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
LeetCode 151 - Reverse Words in a String

Reverse the order of words in s. Collapse extra spaces so the result
has single spaces between words and no leading/trailing space.

Pseudocode
----------
split s on whitespace into words
join words from last to first with a single space
return the joined string
*/

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);
        string ans;
        for (int i = (int)words.size() - 1; i >= 0; --i) {
            if (!ans.empty()) ans += ' ';
            ans += words[i];
        }
        return ans;
    }
};
