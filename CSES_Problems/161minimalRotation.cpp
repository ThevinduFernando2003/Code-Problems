#include <bits/stdc++.h>
using namespace std;

/*
CSES - Minimal Rotation

Least lexicographic rotation of s.

Pseudocode
----------
Duval / Booth-style two pointers on s+s
compare rotations i and j, skip the worse one by k+1
answer is the winning start index
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int)s.size();
    string t = s + s;
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        if (t[i + k] == t[j + k]) k++;
        else {
            if (t[i + k] > t[j + k]) i += k + 1;
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    int pos = min(i, j);
    cout << t.substr(pos, n) << "\n";
    return 0;
}
