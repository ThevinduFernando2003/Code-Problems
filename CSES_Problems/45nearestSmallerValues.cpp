#include <bits/stdc++.h>
using namespace std;

/*
CSES - Nearest Smaller Values

For each position, the nearest index to the left with a strictly smaller value, or 0.

Pseudocode
----------
stack of increasing values (store indices)
for i from 1 to n:
    while stack not empty and a[stack.top] >= a[i]: pop
    answer[i] := stack empty ? 0 : stack.top
    push i
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        cout << (st.empty() ? 0 : st.back()) << " \n"[i == n];
        st.push_back(i);
    }
    return 0;
}
