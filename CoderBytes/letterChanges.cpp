#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Letter Changes

1. Replace every letter with the next letter (z -> a, Z -> A).
2. Capitalize every vowel (a e i o u) in the new string.

Examples:
  "hello*3" -> "Ifmmp*3"
  "fun times!" -> "gvO Ujnft!"

Pseudocode
----------
function LetterChanges(str):
    for each ch in str:
        if ch is a letter:
            if ch is 'z' or 'Z': ch := 'a' or 'A'
            else: ch := next letter
            if ch is a vowel: ch := uppercase(ch)
    return str
*/

string LetterChanges(string str) {
    for (char& ch : str) {
        if (!isalpha((unsigned char)ch)) continue;
        if (ch == 'z') ch = 'a';
        else if (ch == 'Z') ch = 'A';
        else ++ch;
        char low = (char)tolower((unsigned char)ch);
        if (low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u') {
            ch = (char)toupper((unsigned char)ch);
        }
    }
    return str;
}

int main() {
    string str;
    getline(cin, str);
    cout << LetterChanges(str) << endl;
    return 0;
}
