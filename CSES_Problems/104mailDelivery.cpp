#include <bits/stdc++.h>
using namespace std;

/*
CSES - Mail Delivery

Undirected Eulerian circuit starting at 1, using every road exactly once.

Pseudocode
----------
all degrees even, the graph of used edges connected from 1
Hierholzer: stack walk unused edges, append to circuit when stuck
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }
    for (int i = 1; i <= n; i++) if (deg[i] % 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> used(m), it(n + 1);
    vector<int> st = {1}, path;
    while (!st.empty()) {
        int u = st.back();
        while (it[u] < (int)adj[u].size() && used[adj[u][it[u]].second]) it[u]++;
        if (it[u] == (int)adj[u].size()) {
            path.push_back(u);
            st.pop_back();
        } else {
            auto [v, id] = adj[u][it[u]++];
            used[id] = 1;
            st.push_back(v);
        }
    }
    if ((int)path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++) cout << path[i] << " \n"[i + 1 == (int)path.size()];
    return 0;
}
