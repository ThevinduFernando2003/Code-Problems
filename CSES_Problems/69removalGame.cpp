#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = values[i];
    }

    for (int length = 2; length <= n; length++) {
        for (int left = 0; left + length - 1 < n; left++) {
            int right = left + length - 1;
            dp[left][right] = max(
                values[left] - dp[left + 1][right],
                values[right] - dp[left][right - 1]
            );
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}
