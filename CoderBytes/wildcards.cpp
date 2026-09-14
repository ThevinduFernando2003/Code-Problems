#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Wildcards

str is "pattern text". The pattern uses:
  +     one letter
  $     one digit
  {N}   exactly N letters
  *     zero or more letters
Return "true" if the whole text matches the pattern.

Examples:
  "++*{5} jtggggg" -> true
  "$**+*{2} 9mmmrrrkbb" -> true

Pseudocode
----------
function tokenize(pattern):
    walk the pattern and emit +, $, STAR, or LETTERn

function match(tokens, text, ti, si):
    if both consumed: success
    if tokens left is STAR:
        try matching 0, 1, 2, ... letters then the rest
    otherwise consume the required letters/digit and recurse
*/

struct Tok {
    char kind; // '+', '$', '*', 'n'
    int n;
};

vector<Tok> tokenize(const string& p) {
    vector<Tok> t;
    for (int i = 0; i < (int)p.size(); ++i) {
        if (p[i] == '+') t.push_back({'+', 1});
        else if (p[i] == '$') t.push_back({'$', 1});
        else if (p[i] == '*') t.push_back({'*', 0});
        else if (p[i] == '{') {
            int n = 0;
            ++i;
            while (p[i] != '}') n = n * 10 + (p[i++] - '0');
            t.push_back({'n', n});
        }
    }
    return t;
}

bool isLetter(char c) { return isalpha((unsigned char)c); }

bool match(const vector<Tok>& t, const string& s, int ti, int si) {
    if (ti == (int)t.size()) return si == (int)s.size();
    if (t[ti].kind == '*') {
        for (int k = si; k <= (int)s.size(); ++k) {
            bool ok = true;
            for (int i = si; i < k; ++i) if (!isLetter(s[i])) ok = false;
            if (ok && match(t, s, ti + 1, k)) return true;
            if (!ok) break;
        }
        return false;
    }
    if (t[ti].kind == '+') {
        if (si >= (int)s.size() || !isLetter(s[si])) return false;
        return match(t, s, ti + 1, si + 1);
    }
    if (t[ti].kind == '$') {
        if (si >= (int)s.size() || !isdigit((unsigned char)s[si])) return false;
        return match(t, s, ti + 1, si + 1);
    }
    int n = t[ti].n;
    if (si + n > (int)s.size()) return false;
    for (int i = 0; i < n; ++i) if (!isLetter(s[si + i])) return false;
    return match(t, s, ti + 1, si + n);
}

string Wildcards(string str) {
    size_t sp = str.find(' ');
    auto toks = tokenize(str.substr(0, sp));
    string text = str.substr(sp + 1);
    return match(toks, text, 0, 0) ? "true" : "false";
}

int main() {
    string str;
    getline(cin, str);
    cout << Wildcards(str) << endl;
    return 0;
}
