#include <bits/stdc++.h>
using namespace std;

/*
CSES - Tree Diameter

Length of the longest path in a tree.

Pseudocode
----------
BFS/DFS from an arbitrary node to find the farthest node A
BFS/DFS from A to find the farthest node B
diameter := dist(A, B)
*/

vector<vector<int>> adj;
pair<int, int> farthest(int start, int n) {
    vector<int> d(n + 1, -1);
    queue<int> q;
    q.push(start);
    d[start] = 0;
    int best = start;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (d[u] > d[best]) best = u;
        for (int v : adj[u]) if (d[v] < 0) {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    return {best, d[best]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto [a, _] = farthest(1, n);
    cout << farthest(a, n).second << "\n";
    return 0;
}
