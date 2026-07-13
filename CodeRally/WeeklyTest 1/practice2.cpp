#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    // Kadane's algorithm for minimum contiguous subarray sum
    long long minEnding = a[0];
    long long minSubarray = a[0];

    for (int i = 1; i < n; i++) {
        minEnding = min(a[i], minEnding + a[i]);
        minSubarray = min(minSubarray, minEnding);
    }

    long long answer = total;
    if (minSubarray < 0) {
        // Flipping a subarray with sum S changes total by -2S
        answer = total - 2 * minSubarray;
    }

    cout << answer << "\n";
    return 0;
}
