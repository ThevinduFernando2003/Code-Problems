#include <string>
#include <numeric>
using namespace std;

/*
LeetCode 1071 - Greatest Common Divisor of Strings

Return the longest string X such that X repeats to form both str1 and
str2. If no such string exists, return empty.

Pseudocode
----------
if str1 + str2 != str2 + str1: return ""
return prefix of str1 of length gcd(|str1|, |str2|)
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd((int)str1.size(), (int)str2.size()));
    }
};
