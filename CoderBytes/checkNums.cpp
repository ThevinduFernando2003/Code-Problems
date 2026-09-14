#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Check Nums

Have the function CheckNums(num1, num2) return "true" if num2 > num1,
"false" if num2 < num1, and "-1" if they are equal.

Examples:
  3, 122 -> true
  67, 67 -> -1

Pseudocode
----------
function CheckNums(num1, num2):
    if num2 > num1: return "true"
    if num2 < num1: return "false"
    return "-1"
*/

string CheckNums(int num1, int num2) {
    if (num2 > num1) return "true";
    if (num2 < num1) return "false";
    return "-1";
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << CheckNums(a, b) << endl;
    return 0;
}
