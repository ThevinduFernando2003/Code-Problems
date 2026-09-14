#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Division

Have the function Division(num1, num2) return the greatest common
divisor of the two numbers.

Examples:
  7, 3   -> 1
  36, 54 -> 18

Pseudocode
----------
function Division(a, b):
    while b != 0:
        a, b := b, a mod b
    return a
*/

int Division(int num1, int num2) {
    return gcd(num1, num2);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << Division(a, b) << endl;
    return 0;
}
