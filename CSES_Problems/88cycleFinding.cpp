#include <bits/stdc++.h>
using namespace std;

/*
CSES - Cycle Finding

Find any negative cycle in a directed graph, or print NO.

Pseudocode
----------
Bellman-Ford from a dummy source connected to every node
relax n times
if an extra relaxation happens, a negative cycle exists
walk parent pointers n times to land on the cycle, then unwind it
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    struct E { int a, b; long long w; };
    vector<E> e(m);
    for (int i = 0; i < m; i++) cin >> e[i].a >> e[i].b >> e[i].w;
    vector<long long> d(n + 1, 0);
    vector<int> p(n + 1, -1);
    int x = -1;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto [a, b, w] : e) {
            if (d[a] + w < d[b]) {
                d[b] = d[a] + w;
                p[b] = a;
                x = b;
            }
        }
    }
    if (x == -1) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; i++) x = p[x];
    vector<int> cycle;
    int cur = x;
    do {
        cycle.push_back(cur);
        cur = p[cur];
    } while (cur != x);
    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());
    cout << "YES\n";
    for (int i = 0; i < (int)cycle.size(); i++) cout << cycle[i] << " \n"[i + 1 == (int)cycle.size()];
    return 0;
}
