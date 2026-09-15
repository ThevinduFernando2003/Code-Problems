#include <bits/stdc++.h>
using namespace std;

/*
CSES - Longest Palindrome

Longest palindromic substring (Manacher).

Pseudocode
----------
build string with sentinels: ^#a#b#...#$
p[i] = radius at center i
expand while s[i-p[i]]==s[i+p[i]]
track max radius and its center, map back to original
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    cin >> a;
    string s = "^";
    for (char c : a) {
        s += '#';
        s += c;
    }
    s += "#$";
    int n = (int)s.size();
    vector<int> p(n);
    int c = 0, r = 0, best = 0, center = 0;
    for (int i = 1; i < n - 1; i++) {
        if (i < r) p[i] = min(r - i, p[2 * c - i]);
        while (s[i - p[i] - 1] == s[i + p[i] + 1]) p[i]++;
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
        if (p[i] > best) {
            best = p[i];
            center = i;
        }
    }
    int start = (center - best) / 2;
    cout << a.substr(start, best) << "\n";
    return 0;
}
