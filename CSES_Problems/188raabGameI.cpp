#include <bits/stdc++.h>
using namespace std;

/*
CSES - Raab Game I

Two permutations of 1..n. First scores a, second scores b.

Pseudocode
----------
NO if a+b > n or exactly one of a,b is 0
YES all ties: both 1..n
otherwise first plays 1..n; second keeps n-a-b ties then rotates the rest
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        if ((x == 0 && y != 0) || (y == 0 && x != 0) || x + y > n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
        int off = n - x - y;
        vector<int> b;
        for (int i = 1; i <= off; i++) b.push_back(i);
        for (int i = off + x + 1; i <= n; i++) b.push_back(i);
        for (int i = off + 1; i <= off + x; i++) b.push_back(i);
        for (int i = 0; i < n; i++) cout << b[i] << " \n"[i + 1 == n];
    }
    return 0;
}
