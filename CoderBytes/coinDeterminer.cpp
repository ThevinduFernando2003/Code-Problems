#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Coin Determiner

Have the function CoinDeterminer(num) return the fewest coins needed to
make num using denominations 1, 5, 7, 9, 11. Greedy is not always best.

Examples:
  16 -> 2     (11 + 5)
  25 -> 3     (11 + 9 + 5)

Pseudocode
----------
function CoinDeterminer(num):
    coins := [1, 5, 7, 9, 11]
    dp[0] := 0
    dp[1..num] := infinity
    for amount from 1 to num:
        for each coin <= amount:
            dp[amount] := min(dp[amount], dp[amount - coin] + 1)
    return dp[num]
*/

int CoinDeterminer(int num) {
    const int coins[] = {1, 5, 7, 9, 11};
    vector<int> dp(num + 1, 1e9);
    dp[0] = 0;
    for (int a = 1; a <= num; ++a) {
        for (int c : coins) {
            if (c <= a) dp[a] = min(dp[a], dp[a - c] + 1);
        }
    }
    return dp[num];
}

int main() {
    int num;
    cin >> num;
    cout << CoinDeterminer(num) << endl;
    return 0;
}
