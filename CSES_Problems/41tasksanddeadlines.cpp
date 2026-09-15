#include <bits/stdc++.h>
using namespace std;

/*
CSES - Tasks and Deadlines

Reward for a task is deadline - finish time. Maximize total reward.

Pseudocode
----------
sort tasks by duration ascending (shortest first)
t := 0, reward := 0
for each task:
    t := t + duration
    reward := reward + deadline - t
print reward
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    long long t = 0, reward = 0;
    for (auto [dur, dead] : a) {
        t += dur;
        reward += dead - t;
    }
    cout << reward << "\n";
    return 0;
}
