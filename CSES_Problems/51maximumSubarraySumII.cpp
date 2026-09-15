#include <bits/stdc++.h>
using namespace std;

/*
CSES - Maximum Subarray Sum II

Maximum subarray sum among subarrays whose length is between a and b.

Pseudocode
----------
prefix[i] = sum of first i values
for r from a to n:
    the start l of a valid window satisfies r-b <= l <= r-a
    we need prefix[r] - min prefix[l] over that range
    keep prefix values in a deque (increasing) while sliding l
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, A, B;
    cin >> n >> A >> B;
    vector<long long> p(n + 1);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        p[i] = p[i - 1] + x;
    }
    deque<int> dq;
    long long ans = LLONG_MIN;
    for (int r = A; r <= n; r++) {
        int add = r - A;
        while (!dq.empty() && p[dq.back()] >= p[add]) dq.pop_back();
        dq.push_back(add);
        int left = r - B;
        while (!dq.empty() && dq.front() < left) dq.pop_front();
        ans = max(ans, p[r] - p[dq.front()]);
    }
    cout << ans << "\n";
    return 0;
}
