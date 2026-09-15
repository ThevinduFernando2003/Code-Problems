#include <bits/stdc++.h>
using namespace std;

/*
CSES - Police Chase

Minimum number of streets to close so that 1 cannot reach n.
Print the streets.

Pseudocode
----------
undirected edges, capacity 1
max flow = min cut
BFS residual from 1; every original edge from reachable to unreachable
is a cut edge
*/

struct Edge {
    int to, cap, rev, a, b;
};
int n;
vector<vector<Edge>> g;
vector<int> lvl, it;

void add(int a, int b) {
    g[a].push_back({b, 1, (int)g[b].size(), a, b});
    g[b].push_back({a, 1, (int)g[a].size() - 1, b, a});
}

bool bfs() {
    fill(lvl.begin(), lvl.end(), -1);
    queue<int> q;
    lvl[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& e : g[u]) if (e.cap && lvl[e.to] < 0) {
            lvl[e.to] = lvl[u] + 1;
            q.push(e.to);
        }
    }
    return lvl[n] != -1;
}

int dfs(int u, int f) {
    if (u == n) return f;
    for (int& i = it[u]; i < (int)g[u].size(); i++) {
        auto& e = g[u][i];
        if (e.cap && lvl[e.to] == lvl[u] + 1) {
            int got = dfs(e.to, min(f, e.cap));
            if (got) {
                e.cap -= got;
                g[e.to][e.rev].cap += got;
                return got;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    g.assign(n + 1, {});
    lvl.resize(n + 1);
    it.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    while (bfs()) {
        fill(it.begin(), it.end(), 0);
        while (dfs(1, 1e9)) {}
    }
    vector<int> reach(n + 1);
    queue<int> q;
    q.push(1);
    reach[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& e : g[u]) if (e.cap && !reach[e.to]) {
            reach[e.to] = 1;
            q.push(e.to);
        }
    }
    vector<pair<int, int>> cut;
    for (int u = 1; u <= n; u++) if (reach[u])
        for (auto& e : g[u]) if (!reach[e.to] && e.a && e.b) cut.push_back({e.a, e.b});
    cout << cut.size() << "\n";
    for (auto [a, b] : cut) cout << a << " " << b << "\n";
    return 0;
}
