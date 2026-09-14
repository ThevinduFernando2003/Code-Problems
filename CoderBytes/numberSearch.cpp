#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Number Search

Have the function NumberSearch(str) add every number in the string
(multi-digit numbers count as one value), divide by the count of letters,
and return the nearest whole number. If there are no letters, return 0.

Examples:
  "Hello6 9World 2, Nic8e D7ay!" -> (6+9+2+8+7) / 17 = 2
  "H3ello9-9"                    -> (3+9+9) / 5 = 4

Pseudocode
----------
function NumberSearch(str):
    sum := 0
    letters := 0
    i := 0
    while i < length(str):
        if str[i] is a digit:
            value := 0
            while i < length(str) and str[i] is a digit:
                value := value * 10 + digit(str[i])
                i := i + 1
            sum := sum + value
        else:
            if str[i] is a letter:
                letters := letters + 1
            i := i + 1
    if letters is 0: return 0
    return round(sum / letters)
*/

int NumberSearch(string str) {
    long long sum = 0;
    int letters = 0;
    for (int i = 0; i < (int)str.size();) {
        if (isdigit((unsigned char)str[i])) {
            long long value = 0;
            while (i < (int)str.size() && isdigit((unsigned char)str[i])) {
                value = value * 10 + (str[i] - '0');
                ++i;
            }
            sum += value;
        } else {
            if (isalpha((unsigned char)str[i])) ++letters;
            ++i;
        }
    }
    if (letters == 0) return 0;
    return (int)llround((double)sum / letters);
}

int main() {
    string str;
    getline(cin, str);
    cout << NumberSearch(str) << endl;
    return 0;
}
