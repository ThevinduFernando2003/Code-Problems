#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Simple Mode

Have the function SimpleMode(arr) return the mode (most frequent value).
If several values tie, return the one that appears first. If every value
is unique, return -1.

Examples:
  {5, 5, 2, 2, 1} -> 5
  {3, 4, 1, 6, 10} -> -1

Pseudocode
----------
function SimpleMode(arr):
    count := empty map
    firstIndex := empty map
    for i, x in arr:
        count[x] := count[x] + 1
        if x is new: firstIndex[x] := i
    bestCount := 1
    answer := -1
    bestFirst := infinity
    for each x:
        if count[x] > bestCount or (count[x] == bestCount > 1 and firstIndex[x] < bestFirst):
            update answer
    return answer
*/

int SimpleMode(vector<int> arr) {
    unordered_map<int, int> count, first;
    for (int i = 0; i < (int)arr.size(); ++i) {
        if (!count.count(arr[i])) first[arr[i]] = i;
        ++count[arr[i]];
    }
    int best = 1, answer = -1, bestFirst = INT_MAX;
    for (auto& p : count) {
        if (p.second < 2) continue;
        if (p.second > best || (p.second == best && first[p.first] < bestFirst)) {
            best = p.second;
            answer = p.first;
            bestFirst = first[p.first];
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << SimpleMode(arr) << endl;
    return 0;
}
