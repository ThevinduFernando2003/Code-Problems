#include <bits/stdc++.h>
using namespace std;

/*
CSES - Counting Divisors

For each x, print the number of divisors.

Pseudocode
----------
sieve: for i=1..N, for j=i; j<=N; j+=i: d[j]++
answer d[x] in O(1)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int N = 1000000;
    vector<int> d(N + 1);
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i) d[j]++;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << d[x] << "\n";
    }
    return 0;
}
