#include <bits/stdc++.h>
using namespace std;

/*
CSES - Subordinates

Rooted tree at 1. For each node, count employees in its subtree
(not including itself).

Pseudocode
----------
DFS
size[u] := 0
for each child v:
    dfs(v)
    size[u] += 1 + size[v]
*/

int n;
vector<vector<int>> adj;
vector<int> sub;

void dfs(int u) {
    for (int v : adj[u]) {
        dfs(v);
        sub[u] += 1 + sub[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n + 1, {});
    sub.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << sub[i] << " \n"[i == n];
    return 0;
}
