#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, n = (int)chars.size();
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && chars[j] == chars[i]) ++j;
            chars[write++] = chars[i];
            int count = j - i;
            if (count > 1) {
                string digits = to_string(count);
                for (char d : digits) chars[write++] = d;
            }
            i = j;
        }
        return write;
    }
};
