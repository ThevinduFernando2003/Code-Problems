#include <string>
#include <algorithm>
using namespace std;

class Solution {
    static bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int count = 0;
        for (int i = 0; i < k; ++i) count += isVowel(s[i]);
        int best = count;
        for (int i = k; i < (int)s.size(); ++i) {
            count += isVowel(s[i]) - isVowel(s[i - k]);
            best = max(best, count);
        }
        return best;
    }
};
