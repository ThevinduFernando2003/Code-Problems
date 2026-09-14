#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Alphabet Soup

Have the function AlphabetSoup(str) return the letters of str in
alphabetical order. str is letters only.

Examples:
  "coderbyte" -> "bcdeeorty"
  "hooplah"   -> "ahhloop"

Pseudocode
----------
function AlphabetSoup(str):
    sort the characters of str
    return str
*/

string AlphabetSoup(string str) {
    sort(str.begin(), str.end());
    return str;
}

int main() {
    string str;
    getline(cin, str);
    cout << AlphabetSoup(str) << endl;
    return 0;
}
