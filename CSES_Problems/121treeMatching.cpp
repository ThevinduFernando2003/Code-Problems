#include <bits/stdc++.h>
using namespace std;

/*
CSES - Tree Matching

Maximum number of edges in a matching of a tree.

Pseudocode
----------
DFS
for each child, if neither the child nor this node is matched,
take the edge to that child
*/

int n;
vector<vector<int>> adj;
vector<int> used;
int ans = 0;

void dfs(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        if (!used[u] && !used[v]) {
            used[u] = used[v] = 1;
            ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n + 1, {});
    used.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}
