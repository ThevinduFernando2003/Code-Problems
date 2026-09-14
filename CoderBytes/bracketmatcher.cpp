#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Bracket Matcher

Have the function BracketMatcher(str) return 1 if every '(' has a matching
')' in the correct order, otherwise return 0. Ignore all other characters.
A string with no brackets is valid and returns 1.

Examples:
  "(hello (world))"  -> 1
  "((hello (world))" -> 0
  ")("               -> 0
  "hello"            -> 1

Pseudocode
----------
function BracketMatcher(str):
    open := 0

    for each character ch in str:
        if ch is '(':
            open := open + 1
        else if ch is ')':
            if open is 0:
                // a closer with no unmatched opener
                return 0
            open := open - 1

    // valid only when every opener was closed
    if open is 0:
        return 1
    else:
        return 0
*/

int BracketMatcher(string str) {
    int open = 0;
    for (char ch : str) {
        if (ch == '(') {
            ++open;
        } else if (ch == ')') {
            if (open == 0) return 0;
            --open;
        }
    }
    return open == 0 ? 1 : 0;
}

int main() {
    string str;
    getline(cin, str);
    cout << BracketMatcher(str) << endl;
    return 0;
}
