#include <string>
#include <cctype>
using namespace std;

/*
LeetCode 345 - Reverse Vowels of a String

Reverse only the vowels in s (a, e, i, o, u, case insensitive).
Consonants stay in place.

Pseudocode
----------
i := 0, j := |s| - 1
while i < j:
    advance i until it lands on a vowel
    retreat j until it lands on a vowel
    swap s[i] and s[j]
    i := i + 1, j := j - 1
return s
*/

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
