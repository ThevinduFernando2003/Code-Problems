#include <bits/stdc++.h>
using namespace std;

/*
CSES - Sum of Four Values

Find four distinct indices that sum to x. n <= 1000.

Pseudocode
----------
sort (value, index)
for i, then j > i:
    two pointers on (j+1 .. n) for x - a[i] - a[j]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int l = j + 1, r = n - 1;
            long long need = x - a[i].first - a[j].first;
            while (l < r) {
                long long s = a[l].first + a[r].first;
                if (s == need) {
                    cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second << "\n";
                    return 0;
                }
                if (s < need) l++;
                else r--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
