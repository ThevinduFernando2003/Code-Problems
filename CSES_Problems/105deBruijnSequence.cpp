#include <bits/stdc++.h>
using namespace std;

/*
CSES - De Bruijn Sequence

A cyclic binary string of length 2^n that contains every n-bit string
exactly once as a substring (wrap-around). Print a linear string of
length 2^n + n - 1 that covers them.

Pseudocode
----------
nodes are (n-1)-bit strings
an edge 0/1 from u goes to ((u<<1) | bit) & mask
Euler circuit, then emit the start bits plus each edge bit
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "01\n";
        return 0;
    }
    int nodes = 1 << (n - 1);
    vector<int> used(nodes);
    vector<int> st = {0};
    string bits;
    while (!st.empty()) {
        int u = st.back();
        if (used[u] < 2) {
            int b = used[u]++;
            int v = ((u << 1) | b) & (nodes - 1);
            st.push_back(v);
            bits.push_back(char('0' + b));
        } else st.pop_back();
    }
    string ans(n - 1, '0');
    reverse(bits.begin(), bits.end());
    ans += bits;
    cout << ans << "\n";
    return 0;
}
