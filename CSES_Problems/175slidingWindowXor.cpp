#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sliding Window Xor

Xor of all window xors. Generated array.

Pseudocode
----------
window xor: running xor, when sliding xor out the leaving element
(x xor x = 0)
xor those window values
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int> v(n);
    v[0] = (int)x;
    for (int i = 1; i < n; i++) v[i] = (int)((a * v[i - 1] + b) % c);
    int w = 0;
    for (int i = 0; i < k; i++) w ^= v[i];
    int ans = w;
    for (int i = k; i < n; i++) {
        w ^= v[i] ^ v[i - k];
        ans ^= w;
    }
    cout << ans << "\n";
    return 0;
}
