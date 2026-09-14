#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — String Scramble

Have the function StringScramble(str1, str2) return "true" if the characters
in str1 can be rearranged to form str2 (str1 may have extra characters).
Otherwise return "false".

Examples:
  "rkqodlw", "world"     -> true
  "cdore", "coder"       -> true
  "h3llko", "hello"      -> false

Pseudocode
----------
function StringScramble(str1, str2):
    count := empty frequency map
    for each ch in str1:
        count[ch] := count[ch] + 1
    for each ch in str2:
        if count[ch] is 0:
            return false
        count[ch] := count[ch] - 1
    return true
*/

string StringScramble(string str1, string str2) {
    int count[256] = {};
    for (unsigned char ch : str1) ++count[ch];
    for (unsigned char ch : str2) {
        if (count[ch]-- == 0) return "false";
    }
    return "true";
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << StringScramble(str1, str2) << endl;
    return 0;
}
