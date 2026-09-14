#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Swap II

1. Swap the case of every letter.
2. Inside each space-separated token, if two digits have only letters
   between them, swap those two digits.

Examples:
  "6Hello4 -8World, 7 yes3" -> "4hELLO6 -8wORLD, 7 YES3"

Pseudocode
----------
function swapCase(ch):
    if ch is lowercase: return uppercase(ch)
    if ch is uppercase: return lowercase(ch)
    return ch

function SwapII(str):
    for each ch in str: replace ch with swapCase(ch)
    split str into tokens on spaces
    for each token:
        find pairs of digit positions left < right
        if every character strictly between them is a letter:
            swap those two digits (use the first such pair)
    join tokens with spaces
*/

string swapCaseToken(string token) {
    vector<int> digits;
    for (int i = 0; i < (int)token.size(); ++i) {
        if (isdigit((unsigned char)token[i])) digits.push_back(i);
    }
    for (int a = 0; a + 1 < (int)digits.size(); ++a) {
        int L = digits[a], R = digits[a + 1];
        bool onlyLetters = true;
        for (int i = L + 1; i < R; ++i) {
            if (!isalpha((unsigned char)token[i])) onlyLetters = false;
        }
        if (onlyLetters && R > L + 1) {
            swap(token[L], token[R]);
            break;
        }
    }
    return token;
}

string SwapII(string str) {
    for (char& ch : str) {
        if (islower((unsigned char)ch)) ch = (char)toupper((unsigned char)ch);
        else if (isupper((unsigned char)ch)) ch = (char)tolower((unsigned char)ch);
    }
    stringstream ss(str);
    string token, out;
    while (ss >> token) {
        if (!out.empty()) out += ' ';
        out += swapCaseToken(token);
    }
    return out;
}

int main() {
    string str;
    getline(cin, str);
    cout << SwapII(str) << endl;
    return 0;
}
