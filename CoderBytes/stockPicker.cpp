#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Stock Picker

Have the function StockPicker(arr) return the largest profit from one
buy then one later sell. If no positive profit exists, return -1.

Examples:
  {44, 30, 24, 32, 35, 30, 40, 38, 15} -> 16
  {10, 9, 8, 2} -> -1

Pseudocode
----------
function StockPicker(arr):
    minPrice := arr[0]
    best := -1
    for each price after the first:
        if price - minPrice > best: best := price - minPrice
        minPrice := min(minPrice, price)
    if best <= 0: return -1
    return best
*/

int StockPicker(vector<int> arr) {
    int minPrice = arr[0], best = -1;
    for (int i = 1; i < (int)arr.size(); ++i) {
        best = max(best, arr[i] - minPrice);
        minPrice = min(minPrice, arr[i]);
    }
    return best > 0 ? best : -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << StockPicker(arr) << endl;
    return 0;
}
