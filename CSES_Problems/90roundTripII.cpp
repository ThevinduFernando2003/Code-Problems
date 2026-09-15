#include <bits/stdc++.h>
using namespace std;

/*
CSES - Round Trip II

Find any cycle in a directed graph, or print IMPOSSIBLE.

Pseudocode
----------
DFS coloring: 0 white, 1 gray, 2 black
if we edge to a gray node, a cycle is found
unwind the parent chain from the gray node
*/

int n, m;
vector<vector<int>> adj;
vector<int> col, p, cycle;
int start = -1, finish = -1;

bool dfs(int u) {
    col[u] = 1;
    for (int v : adj[u]) {
        if (col[v] == 0) {
            p[v] = u;
            if (dfs(v)) return true;
        } else if (col[v] == 1) {
            start = v;
            finish = u;
            return true;
        }
    }
    col[u] = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.assign(n + 1, {});
    col.assign(n + 1, 0);
    p.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) if (col[i] == 0 && dfs(i)) break;
    if (start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path = {start};
    for (int v = finish; v != start; v = p[v]) path.push_back(v);
    path.push_back(start);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++) cout << path[i] << " \n"[i + 1 == (int)path.size()];
    return 0;
}
