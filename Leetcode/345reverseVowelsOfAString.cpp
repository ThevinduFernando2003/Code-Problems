#include <string>
#include <cctype>
using namespace std;

class Solution {
    static bool isVowel(char c) {
        c = (char)tolower((unsigned char)c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) ++i;
            while (i < j && !isVowel(s[j])) --j;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};
