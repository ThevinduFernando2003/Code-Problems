#include <bits/stdc++.h>
using namespace std;

/*
CSES - Flight Discount

Cheapest path from 1 to n if you may halve the cost of one flight
(integer division).

Pseudocode
----------
build a state graph: (city, usedCoupon 0/1)
Dijkstra
from (u, 0) pay full cost to (v, 0), or pay cost/2 to (v, 1)
from (u, 1) pay full cost to (v, 1)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    const long long INF = 4e18;
    vector<array<long long, 2>> dist(n + 1, {INF, INF});
    using State = tuple<long long, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    dist[1][0] = 0;
    pq.push({0, 1, 0});
    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();
        if (d != dist[u][used]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            if (!used && dist[v][1] > d + w / 2) {
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]) << "\n";
    return 0;
}
