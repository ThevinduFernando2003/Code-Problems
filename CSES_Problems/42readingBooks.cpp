#include <bits/stdc++.h>
using namespace std;

/*
CSES - Reading Books

Two people must read every book. They cannot read the same book at the
same time. Minimum time until both have finished all books.

Pseudocode
----------
the total is at least the sum of all book times
the longest book cannot overlap with itself, so time is also at least
twice that book
answer = max(sum, 2 * max_book)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    cout << max(sum, 2 * mx) << "\n";
    return 0;
}
