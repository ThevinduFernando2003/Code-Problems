#include <bits/stdc++.h>
using namespace std;

/*
CSES - Finding Periods

k is a period if s[i] = s[i+k] for all valid i, i.e. k + Z[k] == n
(and n itself).

Pseudocode
----------
Z-algorithm
for k=1..n-1: if k+Z[k]==n print k
print n
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    vector<int> ans;
    for (int k = 1; k < n; k++) if (k + z[k] == n) ans.push_back(k);
    ans.push_back(n);
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
    return 0;
}
