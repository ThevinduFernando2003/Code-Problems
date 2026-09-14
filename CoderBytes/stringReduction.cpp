#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — String Reduction

str contains only a, b, and c. Two different adjacent letters can be
replaced by the third. Return the shortest length reachable.

Rule of thumb:
  if the string is already all one letter -> length
  if all three counts are even, or all three are odd -> 2
  otherwise -> 1

Examples:
  "abcabc" -> 2
  "cccc"   -> 4

Pseudocode
----------
function StringReduction(str):
    ca, cb, cc := counts of a, b, c
    if two counts are 0: return length
    if (ca, cb, cc) are all even or all odd: return 2
    return 1
*/

int StringReduction(string str) {
    int c[3] = {};
    for (char ch : str) ++c[ch - 'a'];
    int zeros = (c[0] == 0) + (c[1] == 0) + (c[2] == 0);
    if (zeros >= 2) return (int)str.size();
    bool allEven = c[0] % 2 == 0 && c[1] % 2 == 0 && c[2] % 2 == 0;
    bool allOdd = c[0] % 2 && c[1] % 2 && c[2] % 2;
    return (allEven || allOdd) ? 2 : 1;
}

int main() {
    string str;
    getline(cin, str);
    cout << StringReduction(str) << endl;
    return 0;
}
