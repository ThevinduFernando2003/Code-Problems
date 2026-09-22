#include <vector>
#include <string>
using namespace std;

/*
LeetCode 443 - String Compression

Compress consecutive groups in place: a letter followed by its count
when the count is greater than 1. Return the new length.

Pseudocode
----------
write := 0
for each run of identical chars from i to j-1:
    write the character
    if run length > 1: write its decimal digits
    i := j
return write
*/

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
