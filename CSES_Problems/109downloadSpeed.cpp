#include <bits/stdc++.h>
using namespace std;

/*
CSES - Download Speed

Maximum flow from 1 to n with capacities on directed edges.

Pseudocode
----------
Dinic: BFS levels, DFS blocking flow
repeat until the sink is unreachable from the source
*/

struct Edge {
    int to;
    long long cap;
    int rev;
};

int n;
vector<vector<Edge>> g;
vector<int> lvl, it;

void add(int a, int b, long long c) {
    g[a].push_back({b, c, (int)g[b].size()});
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
        for (auto& e : g[u]) if (e.cap > 0 && lvl[e.to] < 0) {
            lvl[e.to] = lvl[u] + 1;
            q.push(e.to);
        }
    }
    return lvl[n] != -1;
}

long long dfs(int u, long long f) {
    if (u == n) return f;
    for (int& i = it[u]; i < (int)g[u].size(); i++) {
        auto& e = g[u][i];
        if (e.cap > 0 && lvl[e.to] == lvl[u] + 1) {
            long long got = dfs(e.to, min(f, e.cap));
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
        long long c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    long long flow = 0, addf;
    while (bfs()) {
        fill(it.begin(), it.end(), 0);
        while ((addf = dfs(1, (long long)4e18))) flow += addf;
    }
    cout << flow << "\n";
    return 0;
}
