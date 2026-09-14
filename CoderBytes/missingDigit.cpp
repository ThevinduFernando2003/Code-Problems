#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Missing Digit

str is an equation using +, -, *, / and one unknown digit written as x.
Return that digit. Division is integer.

Examples:
  "3x + 12 = 46" -> "4"
  "4 - 2 = x"    -> "2"

Pseudocode
----------
function evalSide(text): parse number op number (x already replaced)
function MissingDigit(str):
    split str on '='
    for d from 0 to 9:
        left := left side with x replaced by d
        right := right side with x replaced by d
        if eval(left) == eval(right): return d
*/

long long evalSide(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    long long a = 0, b = 0;
    char op = 0;
    int i = 0, n = (int)s.size();
    if (s[i] == '-') {
        ++i;
        while (i < n && isdigit((unsigned char)s[i])) a = a * 10 + (s[i++] - '0');
        a = -a;
    } else {
        while (i < n && isdigit((unsigned char)s[i])) a = a * 10 + (s[i++] - '0');
    }
    if (i == n) return a;
    op = s[i++];
    if (s[i] == '-') {
        ++i;
        while (i < n && isdigit((unsigned char)s[i])) b = b * 10 + (s[i++] - '0');
        b = -b;
    } else {
        while (i < n && isdigit((unsigned char)s[i])) b = b * 10 + (s[i++] - '0');
    }
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}

string MissingDigit(string str) {
    size_t eq = str.find('=');
    string L = str.substr(0, eq), R = str.substr(eq + 1);
    for (char d = '0'; d <= '9'; ++d) {
        string left = L, right = R;
        for (char& ch : left) if (ch == 'x' || ch == 'X') ch = d;
        for (char& ch : right) if (ch == 'x' || ch == 'X') ch = d;
        if (evalSide(left) == evalSide(right)) return string(1, d);
    }
    return "";
}

int main() {
    string str;
    getline(cin, str);
    cout << MissingDigit(str) << endl;
    return 0;
}
