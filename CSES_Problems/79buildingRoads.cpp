#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return false;
        }

        if (size[a] < size[b]) {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }

    set<int> components;
    for (int i = 1; i <= n; i++) {
        components.insert(dsu.find(i));
    }

    vector<int> roots(components.begin(), components.end());
    cout << roots.size() - 1 << endl;

    for (int i = 1; i < (int)roots.size(); i++) {
        cout << roots[0] << " " << roots[i] << endl;
    }

    return 0;
}
