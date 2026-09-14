#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Run Length

Have the function RunLength(str) encode consecutive repeats.
"wwwggopp" becomes "3w2g1o2p". str is letters only and is never empty.

Examples:
  "wwwggopp" -> "3w2g1o2p"
  "aabbcde"  -> "2a2b1c1d1e"

Pseudocode
----------
function RunLength(str):
    out := empty
    i := 0
    while i < length(str):
        j := i
        while j < length(str) and str[j] == str[i]:
            j := j + 1
        append (j - i) and str[i] to out
        i := j
    return out
*/

string RunLength(string str) {
    string out;
    for (int i = 0; i < (int)str.size();) {
        int j = i;
        while (j < (int)str.size() && str[j] == str[i]) ++j;
        out += to_string(j - i);
        out += str[i];
        i = j;
    }
    return out;
}

int main() {
    string str;
    getline(cin, str);
    cout << RunLength(str) << endl;
    return 0;
}
