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

    vector<int> color(n + 1, -1);
    queue<int> q;

    for (int start = 1; start <= n; start++) {
        if (color[start] != -1) {
            continue;
        }

        color[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 3 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "POSSIBLE" << endl;
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " \n"[i == n];
    }

    return 0;
}
