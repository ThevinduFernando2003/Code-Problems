#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<long long> prev(m + 1, 0), curr(m + 1, 0);

    for (int value = 1; value <= m; value++) {
        if (values[0] == 0 || values[0] == value) {
            prev[value] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        fill(curr.begin(), curr.end(), 0);

        for (int value = 1; value <= m; value++) {
            if (values[i] != 0 && values[i] != value) {
                continue;
            }

            curr[value] = prev[value];
            if (value > 1) {
                curr[value] = (curr[value] + prev[value - 1]) % MOD;
            }
            if (value < m) {
                curr[value] = (curr[value] + prev[value + 1]) % MOD;
            }
        }

        prev.swap(curr);
    }

    long long answer = 0;
    for (int value = 1; value <= m; value++) {
        answer = (answer + prev[value]) % MOD;
    }

    cout << answer << endl;
    return 0;
}
