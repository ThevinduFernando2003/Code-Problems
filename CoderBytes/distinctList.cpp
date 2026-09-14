#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Distinct List

Have the function DistinctList(arr) return how many values must be
removed so every remaining value is unique.

Examples:
  {0, -2, -2, 5, 5, 5} -> 3
  {100, 2, 101, 4}     -> 0

Pseudocode
----------
function DistinctList(arr):
    return length(arr) - number of unique values
*/

int DistinctList(vector<int> arr) {
    return (int)arr.size() - (int)unordered_set<int>(arr.begin(), arr.end()).size();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << DistinctList(arr) << endl;
    return 0;
}
