#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Array Addition

Have the function ArrayAddition(arr) return "true" if any subset of the
other numbers adds up to the largest number. Otherwise "false".

Examples:
  {4, 6, 23, 10, 1, 3} -> true   because 4+6+10+3 = 23
  {5, 7, 16, 1, 2}     -> false

Pseudocode
----------
function ArrayAddition(arr):
    target := maximum value in arr
    remove one copy of target from arr
    reachable := {0}
    for each x in arr:
        for each s in a snapshot of reachable:
            reachable.add(s + x)
    return (target is in reachable)
*/

string ArrayAddition(vector<int> arr) {
    int target = *max_element(arr.begin(), arr.end());
    arr.erase(find(arr.begin(), arr.end(), target));
    unordered_set<int> reach = {0};
    for (int x : arr) {
        vector<int> extra;
        for (int s : reach) extra.push_back(s + x);
        reach.insert(extra.begin(), extra.end());
    }
    return reach.count(target) ? "true" : "false";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << ArrayAddition(arr) << endl;
    return 0;
}
