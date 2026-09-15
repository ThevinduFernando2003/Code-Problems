#include <bits/stdc++.h>
using namespace std;

/*
CSES - Point in Polygon

For each point, INSIDE / OUTSIDE / BOUNDARY of a simple polygon.

Pseudocode
----------
if on any edge: BOUNDARY
else ray cast to +inf x, count crossings (strict y-straddle, not vertex double-count)
odd: INSIDE
*/

struct P {
    long long x, y;
};

int sgn(__int128 v) { return (v > 0) - (v < 0); }

bool onSeg(P a, P b, P c) {
    if ((__int128)(b.x - a.x) * (c.y - a.y) - (__int128)(b.y - a.y) * (c.x - a.x) != 0) return false;
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<P> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    while (m--) {
        P q;
        cin >> q.x >> q.y;
        bool bound = false;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            P a = p[i], b = p[(i + 1) % n];
            if (onSeg(a, b, q)) {
                bound = true;
                break;
            }
            if (a.y > b.y) swap(a, b);
            if (a.y == b.y) continue;
            if (q.y <= a.y || q.y > b.y) continue;
            __int128 cross = (__int128)(b.x - a.x) * (q.y - a.y) - (__int128)(b.y - a.y) * (q.x - a.x);
            if (cross > 0) cnt++;
        }
        if (bound) cout << "BOUNDARY\n";
        else cout << (cnt % 2 ? "INSIDE\n" : "OUTSIDE\n");
    }
    return 0;
}
