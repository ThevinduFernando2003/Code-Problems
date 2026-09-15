#include <bits/stdc++.h>
using namespace std;

/*
CSES - Course Schedule

Print a topological order of n courses, or IMPOSSIBLE if there is a cycle.

Pseudocode
----------
Kahn: queue of indegree-0 nodes
repeatedly pop, append to order, decrease neighbors
if order size < n there is a cycle
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
    }
    if ((int)order.size() < n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 0; i < n; i++) cout << order[i] << " \n"[i == n - 1];
    return 0;
}
