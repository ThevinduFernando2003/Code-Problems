#include <bits/stdc++.h>
using namespace std;

/*
CSES - Static Range Sum Queries

Answer q sums of a[l..r] (1-indexed).

Pseudocode
----------
prefix[0] := 0
prefix[i] := prefix[i-1] + a[i]
query l r := prefix[r] - prefix[l-1]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<long long> p(n + 1);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        p[i] = p[i - 1] + x;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] << "\n";
    }
    return 0;
}
