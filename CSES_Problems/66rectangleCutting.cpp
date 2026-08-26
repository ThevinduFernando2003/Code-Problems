#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int width = 1; width <= a; width++) {
        for (int height = 1; height <= b; height++) {
            dp[width][height] = width * height;

            for (int split = 1; split < width; split++) {
                dp[width][height] = min(
                    dp[width][height],
                    dp[split][height] + dp[width - split][height] + 1
                );
            }

            for (int split = 1; split < height; split++) {
                dp[width][height] = min(
                    dp[width][height],
                    dp[width][split] + dp[width][height - split] + 1
                );
            }
        }
    }

    cout << dp[a][b] << endl;
    return 0;
}
