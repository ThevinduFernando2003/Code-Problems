#include <bits/stdc++.h>
using namespace std;

/*
CSES - Maximum Xor Subarray

Maximum xor of a contiguous subarray.

Pseudocode
----------
binary trie of prefix xors
for each prefix p, query the trie for the value that maximizes p xor t
then insert p
*/

struct Trie {
    int nxt[2 * 200000 * 31][2]{}, sz = 1;
    void insert(int x) {
        int v = 0;
        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (!nxt[v][bit]) nxt[v][bit] = sz++;
            v = nxt[v][bit];
        }
    }
    int query(int x) {
        int v = 0, ans = 0;
        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (nxt[v][bit ^ 1]) {
                ans |= 1 << b;
                v = nxt[v][bit ^ 1];
            } else v = nxt[v][bit];
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Trie t;
    t.insert(0);
    int px = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        px ^= x;
        ans = max(ans, t.query(px));
        t.insert(px);
    }
    cout << ans << "\n";
    return 0;
}
