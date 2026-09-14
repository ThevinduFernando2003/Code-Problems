#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return parse(s, i);
    }
private:
    string parse(const string& s, int& i) {
        string ans;
        while (i < (int)s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int n = 0;
                while (isdigit(s[i])) n = n * 10 + (s[i++] - '0');
                ++i;
                string inner = parse(s, i);
                ++i;
                while (n--) ans += inner;
            } else ans += s[i++];
        }
        return ans;
    }
};
