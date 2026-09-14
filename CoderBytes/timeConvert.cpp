#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Time Convert

Have the function TimeConvert(num) return num minutes as "hours:minutes".
Do not pad minutes with a leading zero.

Examples:
  126 -> "2:6"
  45  -> "0:45"

Pseudocode
----------
function TimeConvert(num):
    return (num / 60) + ":" + (num % 60)
*/

string TimeConvert(int num) {
    return to_string(num / 60) + ":" + to_string(num % 60);
}

int main() {
    int num;
    cin >> num;
    cout << TimeConvert(num) << endl;
    return 0;
}
