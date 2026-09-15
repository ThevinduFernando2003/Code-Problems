#include <bits/stdc++.h>
using namespace std;

/*
CSES - Planets Cycles

For each start planet, how many teleports until a planet repeats.

Pseudocode
----------
the answer is dist-to-cycle + cycle length
DFS/iteration with states (unseen, on stack, done)
when a cycle is found, fill cycle lengths
then DP/fill tree nodes as 1 + answer[next]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nxt(n + 1), ans(n + 1), state(n + 1);
    for (int i = 1; i <= n; i++) cin >> nxt[i];
    function<void(int)> dfs = [&](int u) {
        state[u] = 1;
        int v = nxt[u];
        if (state[v] == 0) {
            dfs(v);
            if (!ans[u]) ans[u] = ans[v] + 1;
        } else if (state[v] == 1) {
            int len = 1, x = v;
            while (x != u) {
                len++;
                x = nxt[x];
            }
            x = v;
            do {
                ans[x] = len;
                x = nxt[x];
            } while (x != v);
        } else {
            ans[u] = ans[v] + 1;
        }
        state[u] = 2;
    };
    for (int i = 1; i <= n; i++) if (state[i] == 0) dfs(i);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}
