#include <bits/stdc++.h>
using namespace std;

/*
CSES - Movie Festival II

k people, each watches movies with no overlap. Maximize movies watched.

Pseudocode
----------
sort movies by ending time
multiset of the time each person becomes free (k zeros)
for each movie:
    pick the person who is free latest but still <= movie start
    (upper_bound(start) then step one left)
    if such a person exists, assign the movie and set free time to movie end
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [](auto& x, auto& y) { return x.second < y.second; });
    multiset<int> free;
    for (int i = 0; i < k; i++) free.insert(0);
    int ans = 0;
    for (auto [l, r] : a) {
        auto it = free.upper_bound(l);
        if (it == free.begin()) continue;
        --it;
        free.erase(it);
        free.insert(r);
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
