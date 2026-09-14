#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Fibonacci Checker

Have the function FibonacciChecker(num) return "yes" if num is a
Fibonacci number, otherwise "no". 0 and 1 are Fibonacci.

Examples:
  5  -> yes
  34 -> yes
  54 -> no

Pseudocode
----------
function FibonacciChecker(num):
    a, b := 0, 1
    while a < num:
        a, b := b, a + b
    return a == num
*/

string FibonacciChecker(long long num) {
    long long a = 0, b = 1;
    while (a < num) {
        long long n = a + b;
        a = b;
        b = n;
    }
    return a == num ? "yes" : "no";
}

int main() {
    long long num;
    cin >> num;
    cout << FibonacciChecker(num) << endl;
    return 0;
}
