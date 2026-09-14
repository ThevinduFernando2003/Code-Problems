
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            if ((bitA | bitB) == bitC) continue;
            if (bitC == 1) ++ans;
            else ans += bitA + bitB;
        }
        return ans;
    }
};
