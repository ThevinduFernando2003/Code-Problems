#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = static_cast<int>(nums.size());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

void printTriplets(const vector<vector<int>>& triplets) {
    cout << "[";
    for (int i = 0; i < static_cast<int>(triplets.size()); i++) {
        cout << "[";
        for (int j = 0; j < static_cast<int>(triplets[i].size()); j++) {
            cout << triplets[i][j];
            if (j + 1 < static_cast<int>(triplets[i].size())) {
                cout << ",";
            }
        }
        cout << "]";
        if (i + 1 < static_cast<int>(triplets.size())) {
            cout << ",";
        }
    }
    cout << "]\n";
}

int main() {
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    printTriplets(threeSum(nums1));

    vector<int> nums2 = {0, 1, 1};
    printTriplets(threeSum(nums2));

    return 0;
}
