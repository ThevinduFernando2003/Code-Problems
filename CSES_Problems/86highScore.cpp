#include <bits/stdc++.h>
using namespace std;

/*
CSES - High Score

Directed graph, maximize score from 1 to n. Edges give points.
A positive cycle reachable from 1 that can still reach n means the
score is unbounded: print -1.

Pseudocode
----------
negate all edge weights and run Bellman-Ford from 1 (n-1 rounds)
one extra round: mark nodes that still relax (on a positive cycle)
DFS/BFS from those nodes on the original graph; if n is reachable, -1
otherwise print -dist[n]  (because we negated)
also n must be reachable from 1
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    struct E { int a, b; long long w; };
    vector<E> e(m);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> e[i].a >> e[i].b >> e[i].w;
        e[i].w = -e[i].w;
        adj[e[i].a].push_back(e[i].b);
    }
    const long long INF = 4e18;
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto [a, b, w] : e) {
            if (dist[a] < INF && dist[a] + w < dist[b]) dist[b] = dist[a] + w;
        }
    }
    vector<int> bad(n + 1);
    for (auto [a, b, w] : e) {
        if (dist[a] < INF && dist[a] + w < dist[b]) bad[b] = 1;
    }
    queue<int> q;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) if (bad[i]) {
        q.push(i);
        vis[i] = 1;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == n) {
            cout << -1 << "\n";
            return 0;
        }
        for (int v : adj[u]) if (!vis[v]) {
            vis[v] = 1;
            q.push(v);
        }
    }
    cout << -dist[n] << "\n";
    return 0;
}
