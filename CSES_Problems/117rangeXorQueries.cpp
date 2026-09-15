#include <bits/stdc++.h>
using namespace std;

/*
CSES - Range Xor Queries

Static range XOR.

Pseudocode
----------
prefixXor[i] := prefixXor[i-1] xor a[i]
query l r := prefixXor[r] xor prefixXor[l-1]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p[i] = p[i - 1] ^ x;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (p[r] ^ p[l - 1]) << "\n";
    }
    return 0;
}
