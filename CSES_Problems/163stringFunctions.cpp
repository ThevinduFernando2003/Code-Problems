#include <bits/stdc++.h>
using namespace std;

/*
CSES - String Functions

Print the Z-array and the KMP prefix function of s.

Pseudocode
----------
Z: window [l,r], copy z[i-l] while inside, else expand
pi: fail links while mismatch, then +1 on match
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> z(n), pi(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    for (int i = 0; i < n; i++) cout << z[i] << " \n"[i + 1 == n];
    for (int i = 0; i < n; i++) cout << pi[i] << " \n"[i + 1 == n];
    return 0;
}
