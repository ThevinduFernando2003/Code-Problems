#include <bits/stdc++.h>
using namespace std;

/*
CSES - Finding Borders

Print all border lengths of s (proper prefixes that are suffixes).

Pseudocode
----------
KMP prefix function pi
k := pi[n-1]
while k > 0: record k, k := pi[k-1]
print recorded lengths in increasing order
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    vector<int> ans;
    for (int k = pi[n - 1]; k; k = pi[k - 1]) ans.push_back(k);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
    if (ans.empty()) cout << "\n";
    return 0;
}
