#include <bits/stdc++.h>
using namespace std;

/*
CSES - Weird Algorithm

Print the Collatz sequence starting from n until 1.

Pseudocode
----------
print n
while n != 1:
    if n is even: n := n / 2
    else: n := 3n + 1
    print n
use 64-bit integers because the sequence can exceed 2^31
*/

int main() {
    long long n;
    cin >> n;
    while (true) {
        cout << n << (n == 1 ? "\n" : " ");
        if (n == 1) break;
        n = (n % 2 == 0) ? n / 2 : n * 3 + 1;
    }
    return 0;
}
