#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sliding Window Minimum

Xor of all window minima. Array generated, n up to 1e7.

Pseudocode
----------
deque of increasing values (indices)
pop back while new is smaller, pop front when out of window
xor the front of each window
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
    deque<int> dq;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && v[dq.back()] >= v[i]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front();
        if (i >= k - 1) ans ^= v[dq.front()];
    }
    cout << ans << "\n";
    return 0;
}
