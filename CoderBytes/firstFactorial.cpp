#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — First Factorial

Have the function FirstFactorial(num) return num! (1 * 2 * ... * num).
The official range is 1..18.

Examples:
  4 -> 24
  8 -> 40320

Pseudocode
----------
function FirstFactorial(num):
    result := 1
    for i from 1 to num:
        result := result * i
    return result
*/

long long FirstFactorial(int num) {
    long long result = 1;
    for (int i = 1; i <= num; ++i){
        result *= i;
    }
    return result;
}

int main() {
    int num;
    cin >> num;
    cout << FirstFactorial(num) << endl;
    return 0;
}
