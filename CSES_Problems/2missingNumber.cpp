#include <bits/stdc++.h>
using namespace std;

/*
CSES - Missing Number

The numbers 1..n appear except one. Print the missing value.

Pseudocode
----------
expected := n * (n + 1) / 2
actual := sum of the n-1 given numbers
answer := expected - actual
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        long long x;
        cin >> x;
        sum += x;
    }
    cout << n * (n + 1) / 2 - sum << "\n";
    return 0;
}
