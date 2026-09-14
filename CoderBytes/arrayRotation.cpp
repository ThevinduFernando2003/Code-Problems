#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Array Rotation

The first element N is how many times to rotate the remaining values
to the left. Return the rotated values concatenated into one string.

Examples:
  {2, 3, 4, 1, 6, 5} -> "41653"     rotate [3,4,1,6,5] left by 2
  {3, 2, 1, 6, 10}   -> "61021"

Pseudocode
----------
function ArrayRotation(arr):
    N := arr[0]
    rest := arr[1..]
    N := N mod length(rest)
    rotated := rest[N..] + rest[0..N)
    return join(rotated) with no separator
*/

string ArrayRotation(vector<int> arr) {
    int n = arr[0];
    vector<int> rest(arr.begin() + 1, arr.end());
    int m = (int)rest.size();
    n %= m;
    string out;
    for (int i = 0; i < m; ++i) out += to_string(rest[(i + n) % m]);
    return out;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << ArrayRotation(arr) << endl;
    return 0;
}
