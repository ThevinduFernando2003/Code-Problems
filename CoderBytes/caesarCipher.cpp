#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Caesar Cipher

Have the function CaesarCipher(str, num) shift every letter forward by
num places, wrapping from z to a. Keep case. Leave other characters.

Examples:
  "Hello", 4 -> "Lipps"
  "abc", 0   -> "abc"

Pseudocode
----------
function CaesarCipher(str, num):
    num := num mod 26
    for each letter ch:
        base := 'A' if uppercase else 'a'
        ch := base + (ch - base + num) mod 26
    return str
*/

string CaesarCipher(string str, int num) {
    num %= 26;
    for (char& ch : str) {
        if (isupper((unsigned char)ch)) ch = (char)('A' + (ch - 'A' + num) % 26);
        else if (islower((unsigned char)ch)) ch = (char)('a' + (ch - 'a' + num) % 26);
    }
    return str;
}

int main() {
    string str;
    int num;
    getline(cin, str);
    cin >> num;
    cout << CaesarCipher(str, num) << endl;
    return 0;
}
