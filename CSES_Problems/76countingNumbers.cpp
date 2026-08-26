#include <bits/stdc++.h>
using namespace std;

long long countUpTo(long long limit) {
    if (limit < 0) {
        return 0;
    }

    string digits = to_string(limit);
    int n = digits.size();
    long long memo[20][2][2][11];
    memset(memo, -1, sizeof(memo));

    function<long long(int, bool, bool, int)> dfs =
        [&](int pos, bool tight, bool started, int prevDigit) -> long long {
        if (pos == n) {
            return started ? 1 : 0;
        }

        long long& cached = memo[pos][tight][started][prevDigit + 1];
        if (cached != -1) {
            return cached;
        }

        int maxDigit = tight ? digits[pos] - '0' : 9;
        long long ways = 0;

        for (int digit = 0; digit <= maxDigit; digit++) {
            if (started && digit == prevDigit) {
                continue;
            }

            bool nextTight = tight && digit == maxDigit;
            bool nextStarted = started || digit > 0;
            int nextPrev = nextStarted ? digit : prevDigit;

            ways += dfs(pos + 1, nextTight, nextStarted, nextPrev);
        }

        return cached = ways;
    };

    return dfs(0, true, false, -1);
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << countUpTo(b) - countUpTo(a - 1) << endl;
    return 0;
}
