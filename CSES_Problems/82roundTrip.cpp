#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, -1);
    vector<int> order;
    vector<bool> visited(n + 1, false);

    function<bool(int)> dfs = [&](int node) -> bool {
        visited[node] = true;
        order.push_back(node);

        for (int neighbor : adj[node]) {
            if (neighbor == parent[node]) {
                continue;
            }

            if (visited[neighbor]) {
                vector<int> cycle;
                cycle.push_back(neighbor);

                for (int i = (int)order.size() - 1; i >= 0; i--) {
                    cycle.push_back(order[i]);
                    if (order[i] == neighbor) {
                        break;
                    }
                }

                cout << cycle.size() << endl;
                for (int city : cycle) {
                    cout << city << " ";
                }
                cout << endl;
                return true;
            }

            parent[neighbor] = node;
            if (dfs(neighbor)) {
                return true;
            }
        }

        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i)) {
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
