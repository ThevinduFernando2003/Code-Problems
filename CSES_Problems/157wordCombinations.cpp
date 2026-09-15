#include <bits/stdc++.h>
using namespace std;

/*
CSES - Word Combinations

Number of ways to form the string from a dictionary, mod 1e9+7.

Pseudocode
----------
insert all words in a trie
dp[0] := 1
for i = 0..n-1 if dp[i]:
    walk trie from i, add dp[i] to dp[end] at every word end
*/

const int MOD = 1e9 + 7;

struct Trie {
    vector<array<int, 26>> nxt;
    vector<char> end;
    Trie() { nxt.push_back({}); end.push_back(0); }
    void insert(const string& s) {
        int v = 0;
        for (char c : s) {
            int x = c - 'a';
            if (!nxt[v][x]) {
                nxt[v][x] = (int)nxt.size();
                nxt.push_back({});
                end.push_back(0);
            }
            v = nxt[v][x];
        }
        end[v] = 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int k;
    cin >> k;
    Trie tr;
    while (k--) {
        string w;
        cin >> w;
        tr.insert(w);
    }
    int n = (int)s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) if (dp[i]) {
        int v = 0;
        for (int j = i; j < n; j++) {
            int x = s[j] - 'a';
            if (!tr.nxt[v][x]) break;
            v = tr.nxt[v][x];
            if (tr.end[v]) dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
