#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            long long best = LLONG_MAX;
            if (i > 0) {
                best = min(best, dp[i - 1][j]);
            }
            if (j > 0) {
                best = min(best, dp[i][j - 1]);
            }

            dp[i][j] = best + grid[i][j];
        }
    }

    cout << dp[n - 1][n - 1] << endl;
    return 0;
}
