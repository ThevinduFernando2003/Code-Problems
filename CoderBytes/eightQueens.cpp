#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Eight Queens

str is eight board positions such as "(2,1)(4,3)(6,3)(8,4)(3,4)(1,6)(7,7)(5,8)".
Return "true" if no two queens share a row, column, or diagonal.

Examples:
  "(2,1)(4,2)(6,3)(8,4)(3,5)(1,6)(7,7)(5,8)" -> true
  "(2,1)(4,3)(6,3)(8,4)(3,4)(1,6)(7,7)(5,8)" -> false

Pseudocode
----------
function EightQueens(str):
    parse all (r, c) pairs
    for each pair of queens i < j:
        if same row or same column: return false
        if abs(row i - row j) == abs(col i - col j): return false
    return true
*/

string EightQueens(string str) {
    vector<pair<int, int>> q;
    for (int i = 0; i < (int)str.size(); ++i) {
        if (str[i] != '(') continue;
        int r = 0, c = 0;
        sscanf(str.c_str() + i, "(%d,%d)", &r, &c);
        q.push_back({r, c});
    }
    for (int i = 0; i < (int)q.size(); ++i) {
        for (int j = i + 1; j < (int)q.size(); ++j) {
            if (q[i].first == q[j].first || q[i].second == q[j].second) return "false";
            if (abs(q[i].first - q[j].first) == abs(q[i].second - q[j].second)) return "false";
        }
    }
    return "true";
}

int main() {
    string str;
    getline(cin, str);
    cout << EightQueens(str) << endl;
    return 0;
}
