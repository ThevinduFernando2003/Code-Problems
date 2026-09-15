#include <bits/stdc++.h>
using namespace std;

/*
CSES - Shortest Routes I

Directed flights with positive costs. Print the cheapest path from 1
to every city.

Pseudocode
----------
Dijkstra from city 1
dist[1] := 0, others inf
pop the unused node with smallest dist
relax outgoing flights
print dist[1..n]
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
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        if (cost > dist[node]) continue;
        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " \n"[i == n];
    return 0;
}
