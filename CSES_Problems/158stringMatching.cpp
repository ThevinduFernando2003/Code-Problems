#include <bits/stdc++.h>
using namespace std;

/*
CSES - String Matching

Count occurrences of pattern p in string s.

Pseudocode
----------
KMP: pi of p + '#' + s
count pi[i] == |p|
*/

vector<int> prefix(const string& s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, p;
    cin >> s >> p;
    auto pi = prefix(p + "#" + s);
    int ans = 0;
    for (int x : pi) if (x == (int)p.size()) ans++;
    cout << ans << "\n";
    return 0;
}
