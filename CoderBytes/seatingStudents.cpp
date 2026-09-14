#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Seating Students

arr = [K, r1, r2, ...] where K is the number of desks (even) in two
columns: 1 top-left, 2 top-right, 3 under 1, 4 under 2, ...
The remaining values are occupied desks.
Return how many ways two students can sit in adjacent empty seats
(side-by-side, or directly in front/behind).

Example:
  [12, 2, 6, 7, 11] -> 6

Pseudocode
----------
function SeatingStudents(arr):
    K := arr[0]
    occupied := set(arr[1..])
    ways := 0
    for desk d from 1 to K:
        if d is occupied: continue
        if d is odd and d+1 <= K and d+1 is empty:  // pair across the aisle
            ways := ways + 1
        if d + 2 <= K and d+2 is empty:             // pair behind (count once from the front)
            ways := ways + 1
    return ways
*/

int SeatingStudents(vector<int> arr) {
    int K = arr[0];
    unordered_set<int> occ(arr.begin() + 1, arr.end());
    int ways = 0;
    for (int d = 1; d <= K; ++d) {
        if (occ.count(d)) continue;
        if (d % 2 == 1 && d + 1 <= K && !occ.count(d + 1)) ++ways;
        if (d + 2 <= K && !occ.count(d + 2)) ++ways;
    }
    return ways;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << SeatingStudents(arr) << endl;
    return 0;
}
