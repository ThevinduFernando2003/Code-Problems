#include <bits/stdc++.h>
using namespace std;

/*
CSES - Teleporters Path

Directed Eulerian path from 1 to n using every teleporter once.

Pseudocode
----------
outdeg[1]-indeg[1] == 1, indeg[n]-outdeg[n] == 1, others equal
Hierholzer from 1 on unused directed edges
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1), out(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        out[a]++;
        in[b]++;
    }
    if (out[1] != in[1] + 1 || in[n] != out[n] + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 2; i < n; i++) if (in[i] != out[i]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> st = {1}, path;
    while (!st.empty()) {
        int u = st.back();
        if (adj[u].empty()) {
            path.push_back(u);
            st.pop_back();
        } else {
            int v = adj[u].back();
            adj[u].pop_back();
            st.push_back(v);
        }
    }
    reverse(path.begin(), path.end());
    if ((int)path.size() != m + 1 || path.front() != 1 || path.back() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 0; i < (int)path.size(); i++) cout << path[i] << " \n"[i + 1 == (int)path.size()];
    return 0;
}
