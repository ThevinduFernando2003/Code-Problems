#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int maxSum = accumulate(coins.begin(), coins.end(), 0);
    vector<long long> dp(maxSum + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int sum = maxSum; sum >= coin; sum--) {
            dp[sum] += dp[sum - coin];
        }
    }

    vector<int> sums;
    for (int sum = 1; sum <= maxSum; sum++) {
        if (dp[sum] > 0) {
            sums.push_back(sum);
        }
    }

    cout << sums.size() << endl;
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
