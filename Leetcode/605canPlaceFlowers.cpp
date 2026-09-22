#include <vector>
using namespace std;

/*
LeetCode 605 - Can Place Flowers

Place n flowers in empty plots so that no two flowers are adjacent.
Return true if that is possible.

Pseudocode
----------
for i from 0 to n-1 while flowers remain:
    if plot i is empty and both neighbors are empty (or missing):
        plant at i
        n := n - 1
return n <= 0
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = (int)flowerbed.size();
        for (int i = 0; i < m && n > 0; ++i) {
            if (flowerbed[i] != 0) continue;
            bool left = i == 0 || flowerbed[i - 1] == 0;
            bool right = i == m - 1 || flowerbed[i + 1] == 0;
            if (left && right) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n <= 0;
    }
};
