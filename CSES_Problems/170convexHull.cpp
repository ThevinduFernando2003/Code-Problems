#include <bits/stdc++.h>
using namespace std;

/*
CSES - Convex Hull

Monotone chain, including colinear boundary points.

Pseudocode
----------
sort unique points by x then y
build lower hull: pop while last turn is not left (or colinear if excluding)
build upper hull similarly
concatenate, drop duplicated endpoints
*/

struct P {
    long long x, y;
    bool operator<(const P& o) const { return x == o.x ? y < o.y : x < o.x; }
    bool operator==(const P& o) const { return x == o.x && y == o.y; }
};

long long cross(P a, P b, P c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = (int)a.size();
    if (n <= 2) {
        cout << n << "\n";
        for (auto p : a) cout << p.x << " " << p.y << "\n";
        return 0;
    }
    vector<P> lo, up;
    for (int i = 0; i < n; i++) {
        while (lo.size() >= 2 && cross(lo[lo.size() - 2], lo.back(), a[i]) < 0) lo.pop_back();
        lo.push_back(a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (up.size() >= 2 && cross(up[up.size() - 2], up.back(), a[i]) < 0) up.pop_back();
        up.push_back(a[i]);
    }
    lo.pop_back();
    up.pop_back();
    lo.insert(lo.end(), up.begin(), up.end());
    cout << lo.size() << "\n";
    for (auto p : lo) cout << p.x << " " << p.y << "\n";
    return 0;
}
