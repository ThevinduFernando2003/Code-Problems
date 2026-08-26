#include <bits/stdc++.h>
using namespace std;

struct Project {
    int start;
    int end;
    int profit;
};

int main() {
    int n;
    cin >> n;

    vector<Project> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].profit;
    }

    sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
        return a.end < b.end;
    });

    vector<long long> dp(n, 0);
    vector<int> endDays;
    endDays.reserve(n);

    for (int i = 0; i < n; i++) {
        long long best = projects[i].profit;

        int index = upper_bound(endDays.begin(), endDays.end(), projects[i].start) - endDays.begin() - 1;
        if (index >= 0) {
            best = max(best, dp[index] + projects[i].profit);
        }

        if (i > 0) {
            best = max(best, dp[i - 1]);
        }

        dp[i] = best;
        endDays.push_back(projects[i].end);
    }

    cout << dp[n - 1] << endl;
    return 0;
}
