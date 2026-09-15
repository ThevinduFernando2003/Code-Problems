/*
CSES - Removing Digits

From n, subtract one of its digits. Minimum steps to 0.

Pseudocode
----------
dp[0]:=0
dp[x] := 1 + min dp[x-digit] over digits of x
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int value = 1; value <= n; value++) {
        int temp = value;
        while (temp > 0) {
            int digit = temp % 10;
            dp[value] = min(dp[value], dp[value - digit] + 1);
            temp /= 10;
        }
    }

    cout << dp[n] << endl;
    return 0;
}
