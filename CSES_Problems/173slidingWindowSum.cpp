#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sliding Window Sum

Array generated from x, n, k, a,b,c. Print xor of all window sums of length k.

Pseudocode
----------
x[1] given, x[i] = (a*x[i-1]+b) mod c
maintain running sum of k elements, xor all of them
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long> v(n);
    v[0] = x;
    for (int i = 1; i < n; i++) v[i] = (a * v[i - 1] + b) % c;
    long long s = 0;
    for (int i = 0; i < k; i++) s += v[i];
    long long ans = s;
    for (int i = k; i < n; i++) {
        s += v[i] - v[i - k];
        ans ^= s;
    }
    cout << ans << "\n";
    return 0;
}
