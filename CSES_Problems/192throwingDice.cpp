#include <bits/stdc++.h>
using namespace std;

/*
CSES - Throwing Dice

Number of ways to get sum n with any number of 6-sided dice, mod 1e9+7.
Equivalent to dice combinations with faces 1..6.

Pseudocode
----------
dp[0]=1
dp[i] += dp[i-f] for f=1..6
n up to 1e18: linear recurrence matrix exponentiation 6x6
*/

const long long MOD = 1e9 + 7;

using Mat = array<array<long long, 6>, 6>;

Mat mul(const Mat& a, const Mat& b) {
    Mat r{};
    for (int i = 0; i < 6; i++)
        for (int k = 0; k < 6; k++)
            for (int j = 0; j < 6; j++)
                r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % MOD;
    return r;
}

Mat mpow(Mat b, long long e) {
    Mat r{};
    for (int i = 0; i < 6; i++) r[i][i] = 1;
    while (e) {
        if (e & 1) r = mul(r, b);
        b = mul(b, b);
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }
    vector<long long> dp(7);
    dp[0] = 1;
    for (int i = 1; i <= 6; i++)
        for (int f = 1; f <= i; f++) dp[i] = (dp[i] + dp[i - f]) % MOD;
    if (n <= 6) {
        cout << dp[n] << "\n";
        return 0;
    }
    Mat b{};
    for (int i = 0; i < 6; i++) b[0][i] = 1;
    for (int i = 1; i < 6; i++) b[i][i - 1] = 1;
    Mat p = mpow(b, n - 6);
    long long ans = 0;
    for (int i = 0; i < 6; i++) ans = (ans + p[0][i] * dp[6 - i]) % MOD;
    cout << ans << "\n";
    return 0;
}
