#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Roman Numeral Reduction

str is a (possibly inefficient) Roman numeral. Return the same value
written in standard compact form.

Examples:
  "XXXVVIIIIIIIIII" -> "LII"     (52)
  "DDLL"            -> "MC"      (1100)

Pseudocode
----------
function toInt(roman):
    scan left to right; if a smaller value precedes a larger, subtract it
function toRoman(n):
    greedily emit M, CM, D, CD, C, XC, L, XL, X, IX, V, IV, I
function RomanNumeralReduction(str):
    return toRoman(toInt(str))
*/

int toInt(const string& s) {
    unordered_map<char, int> v{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int tot = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        int cur = v[s[i]];
        int nxt = (i + 1 < (int)s.size()) ? v[s[i + 1]] : 0;
        tot += (cur < nxt) ? -cur : cur;
    }
    return tot;
}

string toRoman(int n) {
    const pair<int, const char*> table[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    string out;
    for (auto [val, sym] : table) {
        while (n >= val) {
            out += sym;
            n -= val;
        }
    }
    return out;
}

string RomanNumeralReduction(string str) {
    return toRoman(toInt(str));
}

int main() {
    string str;
    getline(cin, str);
    cout << RomanNumeralReduction(str) << endl;
    return 0;
}
