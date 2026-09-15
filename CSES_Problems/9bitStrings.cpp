/*
CSES - Bit Strings

Number of bit strings of length n, modulo 1e9+7.

Pseudocode
----------
answer := 2^n mod 1e9+7  (fast pow)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long num;
    num = (long long)pow(2,n);
    cout << num << endl;
    return 0;
}