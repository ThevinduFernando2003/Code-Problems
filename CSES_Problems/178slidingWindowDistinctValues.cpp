#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sliding Window Distinct Values

Distinct counts in each window of k.

Pseudocode
----------
freq map, distinct counter
add a[i], if freq becomes 1 distinct++
remove a[i-k], if freq becomes 0 distinct--
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> freq;
    freq.reserve(n * 2);
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (++freq[a[i]] == 1) d++;
        if (i >= k && --freq[a[i - k]] == 0) d--;
        if (i >= k - 1) cout << d << " \n"[i == n - 1];
    }
    return 0;
}
