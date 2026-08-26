#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int budget = x; budget >= price[i]; budget--) {
            dp[budget] = max(dp[budget], dp[budget - price[i]] + pages[i]);
        }
    }

    cout << dp[x] << endl;
    return 0;
}
