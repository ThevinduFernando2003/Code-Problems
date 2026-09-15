#include <bits/stdc++.h>
using namespace std;

/*
CSES - Flight Routes

Print the k cheapest path costs from 1 to n (paths may share edges).

Pseudocode
----------
Dijkstra, but keep up to k distances per node
push a neighbor if we do not yet have k distances, or this cost is
better than the worst stored one
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<vector<long long>> dist(n + 1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if ((int)dist[u].size() >= k) continue;
        dist[u].push_back(d);
        for (auto [v, w] : adj[u]) pq.push({d + w, v});
    }
    for (int i = 0; i < k; i++) cout << dist[n][i] << " \n"[i == k - 1];
    return 0;
}
