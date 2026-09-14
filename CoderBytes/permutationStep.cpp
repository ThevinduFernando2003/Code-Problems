#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Permutation Step

Have the function PermutationStep(num) return the next larger integer
that uses exactly the same digits. If none exists, return -1.

Examples:
  123  -> 132
  12453 -> 12534
  111  -> -1

Pseudocode
----------
function PermutationStep(num):
    digits := characters of num
    find the next permutation in lexicographic order
    if that permutation is larger: return it
    else return -1
*/

int PermutationStep(int num) {
    string s = to_string(num);
    if (!next_permutation(s.begin(), s.end())) return -1;
    return stoi(s);
}

int main() {
    int num;
    cin >> num;
    cout << PermutationStep(num) << endl;
    return 0;
}
