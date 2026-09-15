#include <bits/stdc++.h>
using namespace std;

/*
CSES - Common Divisors

Maximum gcd of two distinct array values.

Pseudocode
----------
cnt[x] := how many times x appears
for g = 1e6 downto 1:
    multiples := sum cnt[k*g]
    if multiples >= 2: print g and stop
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    const int N = 1000000;
    vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int g = N; g >= 1; g--) {
        int c = 0;
        for (int x = g; x <= N; x += g) {
            c += cnt[x];
            if (c >= 2) {
                cout << g << "\n";
                return 0;
            }
        }
    }
    return 0;
}
