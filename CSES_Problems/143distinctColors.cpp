#include <bits/stdc++.h>
using namespace std;

/*
CSES - Distinct Colors

Number of distinct node colors in every subtree.

Pseudocode
----------
small-to-large merging
dfs returns a pointer to a set of colors in the subtree
always merge smaller set into larger
answer[u] := size of the set at u
*/

int n;
vector<vector<int>> adj;
vector<int> col, ans;
vector<set<int>> st;

int dfs(int u, int p) {
    int id = u;
    for (int v : adj[u]) if (v != p) {
        int cid = dfs(v, u);
        if (st[cid].size() > st[id].size()) swap(id, cid);
        st[id].insert(st[cid].begin(), st[cid].end());
    }
    st[id].insert(col[u]);
    ans[u] = (int)st[id].size();
    return id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    col.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> col[i];
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    st.resize(n + 1);
    ans.assign(n + 1, 0);
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}
