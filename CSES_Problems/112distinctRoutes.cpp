#include <bits/stdc++.h>
using namespace std;

/*
CSES - Distinct Routes

Maximum number of edge-disjoint paths from 1 to n. Print the paths.

Pseudocode
----------
unit-capacity directed max flow
then walk residual backward edges from 1, greedily recovering each path
*/

struct Edge {
    int to, cap, rev;
};
int n;
vector<vector<Edge>> g;
vector<int> lvl, it;

void add(int a, int b) {
    g[a].push_back({b, 1, (int)g[b].size()});
    g[b].push_back({a, 0, (int)g[a].size() - 1});
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
    int flow = 0;
    while (bfs()) {
        fill(it.begin(), it.end(), 0);
        while (dfs(1, 1)) flow++;
    }
    cout << flow << "\n";
    for (int p = 0; p < flow; p++) {
        vector<int> path = {1};
        int u = 1;
        while (u != n) {
            for (auto& e : g[u]) if (!e.cap && e.to != 0 && g[e.to][e.rev].cap) {
                g[e.to][e.rev].cap = 0;
                u = e.to;
                path.push_back(u);
                break;
            }
        }
        cout << path.size() << "\n";
        for (int i = 0; i < (int)path.size(); i++) cout << path[i] << " \n"[i + 1 == (int)path.size()];
    }
    return 0;
}
