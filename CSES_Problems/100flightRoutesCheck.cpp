#include <bits/stdc++.h>
using namespace std;

/*
CSES - Flight Routes Check

Check whether every city can reach every other city via flights.
If not, print NO and one ordered pair (a, b) with no path a -> b.

Pseudocode
----------
if some node is unreachable from 1 in the original graph: NO 1 that-node
if some node cannot reach 1 (unreachable from 1 in the reversed graph):
    NO that-node 1
otherwise YES
(weakly, if 1 can reach all and all can reach 1, the graph is strongly
connected)
*/

void dfs(int u, vector<vector<int>>& adj, vector<int>& seen) {
    seen[u] = 1;
    for (int v : adj[u]) if (!seen[v]) dfs(v, adj, seen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), radj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vector<int> a(n + 1), b(n + 1);
    dfs(1, adj, a);
    dfs(1, radj, b);
    for (int i = 1; i <= n; i++) if (!a[i]) {
        cout << "NO\n1 " << i << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) if (!b[i]) {
        cout << "NO\n" << i << " 1\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}
