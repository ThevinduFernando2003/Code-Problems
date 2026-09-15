#include <bits/stdc++.h>
using namespace std;

/*
CSES - Planets Queries II

Minimum teleports from a to b in a functional graph, or -1.

Pseudocode
----------
each component is a cycle with trees feeding into it
DFS/iterative to assign:
    which cycle a node reaches, index on that cycle, distance to cycle
if a and b are not in the same cycle-component: -1
if b is on the unique path from a:
    if both on cycle: clockwise distance
    if a is in a tree: walk to cycle then around, or land on b before the cycle
*/

int n, q;
vector<int> nxt, vis, inCycle, cycId, cycPos, cycLen, distToCyc, root;
vector<vector<int>> radj;
int cid = 0;

void build() {
    vis.assign(n + 1, 0);
    inCycle.assign(n + 1, 0);
    cycId.assign(n + 1, -1);
    cycPos.assign(n + 1, -1);
    cycLen.assign(n + 1, 0);
    distToCyc.assign(n + 1, 0);
    root.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int u = i;
        vector<int> path;
        while (!vis[u]) {
            vis[u] = 1;
            path.push_back(u);
            u = nxt[u];
        }
        int start = -1;
        for (int j = 0; j < (int)path.size(); j++) if (path[j] == u) start = j;
        if (start != -1) {
            int len = (int)path.size() - start;
            for (int j = start; j < (int)path.size(); j++) {
                inCycle[path[j]] = 1;
                cycId[path[j]] = cid;
                cycPos[path[j]] = j - start;
                cycLen[path[j]] = len;
                root[path[j]] = path[j];
            }
            cid++;
        }
    }
    function<void(int, int, int)> dfs = [&](int u, int r, int d) {
        root[u] = r;
        distToCyc[u] = d;
        cycId[u] = cycId[r];
        cycLen[u] = cycLen[r];
        for (int v : radj[u]) if (!inCycle[v] && !root[v]) dfs(v, r, d + 1);
    };
    for (int i = 1; i <= n; i++) if (inCycle[i]) {
        for (int v : radj[i]) if (!inCycle[v]) dfs(v, i, 1);
    }
}

int lift(int u, int k) {
    while (k--) u = nxt[u];
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    nxt.resize(n + 1);
    radj.assign(n + 1, {});
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        radj[nxt[i]].push_back(i);
    }
    build();
    const int LOG = 20;
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) up[0][i] = nxt[i];
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n; i++) up[j][i] = up[j - 1][up[j - 1][i]];
    auto jump = [&](int x, int k) {
        for (int j = 0; j < LOG; j++) if (k >> j & 1) x = up[j][x];
        return x;
    };
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (cycId[a] != cycId[b] || cycId[a] == -1) {
            cout << -1 << "\n";
            continue;
        }
        if (!inCycle[a] && !inCycle[b]) {
            if (distToCyc[a] < distToCyc[b] || jump(a, distToCyc[a] - distToCyc[b]) != b) {
                cout << -1 << "\n";
            } else cout << distToCyc[a] - distToCyc[b] << "\n";
        } else if (!inCycle[a] && inCycle[b]) {
            int steps = distToCyc[a];
            int on = jump(a, steps);
            int len = cycLen[on];
            int extra = (cycPos[b] - cycPos[on] + len) % len;
            cout << steps + extra << "\n";
        } else if (inCycle[a] && inCycle[b]) {
            int len = cycLen[a];
            cout << (cycPos[b] - cycPos[a] + len) % len << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
