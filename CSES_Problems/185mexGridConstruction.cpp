#include <bits/stdc++.h>
using namespace std;

/*
CSES - Mex Grid Construction

Fill n x n so a[i][j] is mex of earlier values in row i and column j.

Pseudocode
----------
a[i][j] := i xor j  (0-indexed) satisfies the mex-of-row-and-column property
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cout << (i ^ j) << " \n"[j + 1 == n];
    return 0;
}
