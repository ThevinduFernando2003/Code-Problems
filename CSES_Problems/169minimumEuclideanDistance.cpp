#include <bits/stdc++.h>
using namespace std;

/*
CSES - Minimum Euclidean Distance

Closest pair of points, print squared distance.

Pseudocode
----------
sort by x
divide and conquer: d = min(left, right)
strip of width sqrt(d) around mid, sort by y
each point checks only next ~7 in y-order
*/

using ll = long long;
struct P {
    ll x, y;
};

ll dist2(const P& a, const P& b) {
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

ll rec(vector<P>& a, int l, int r) {
    if (r - l <= 3) {
        ll d = LLONG_MAX;
        for (int i = l; i < r; i++)
            for (int j = i + 1; j < r; j++) d = min(d, dist2(a[i], a[j]));
        sort(a.begin() + l, a.begin() + r, [](P u, P v) { return u.y < v.y; });
        return d;
    }
    int m = (l + r) / 2;
    ll mx = a[m].x;
    ll d = min(rec(a, l, m), rec(a, m, r));
    inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r, [](P u, P v) { return u.y < v.y; });
    vector<P> strip;
    for (int i = l; i < r; i++)
        if ((a[i].x - mx) * (a[i].x - mx) < d) strip.push_back(a[i]);
    for (int i = 0; i < (int)strip.size(); i++)
        for (int j = i + 1; j < (int)strip.size() && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < d; j++)
            d = min(d, dist2(strip[i], strip[j]));
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end(), [](P u, P v) { return u.x < v.x; });
    cout << rec(a, 0, n) << "\n";
    return 0;
}
