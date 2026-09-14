#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Gas Station

strArr[0] is N. The next N strings are "gas:cost" on a circular route.
Return the smallest 1-based station index that can complete a full loop,
or "impossible".

Examples:
  {"4", "3:1", "2:2", "1:2", "0:1"} -> "1"
  {"4", "1:1", "2:2", "1:2", "0:1"} -> "impossible"

Pseudocode
----------
function GasStation(arr):
    N := arr[0]
    parse gas[i], cost[i]
    for start from 1 to N:
        tank := 0
        ok := true
        for N steps around the circle:
            tank := tank + gas - cost
            if tank < 0: ok := false
        if ok: return start
    return "impossible"
*/

string GasStation(vector<string> arr) {
    int n = stoi(arr[0]);
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; ++i) {
        size_t c = arr[i + 1].find(':');
        gas[i] = stoi(arr[i + 1].substr(0, c));
        cost[i] = stoi(arr[i + 1].substr(c + 1));
    }
    for (int start = 0; start < n; ++start) {
        long long tank = 0;
        bool ok = true;
        for (int step = 0; step < n; ++step) {
            int i = (start + step) % n;
            tank += gas[i] - cost[i];
            if (tank < 0) {
                ok = false;
                break;
            }
        }
        if (ok) return to_string(start + 1);
    }
    return "impossible";
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << GasStation(arr) << endl;
    return 0;
}
