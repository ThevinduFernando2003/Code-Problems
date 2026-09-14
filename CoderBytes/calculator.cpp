#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Calculator

Have the function Calculator(str) evaluate an arithmetic expression with
+, -, *, / and parentheses. Adjacent groups imply multiplication:
"6(4)" is 24 and "(2)(3)" is 6. Division is exact for the official tests.

Examples:
  "6*(4/2)+3*1" -> "15"
  "6(4)"        -> "24"
  "2+(3-1)*8"   -> "18"

Pseudocode
----------
function insertImpliedMultiply(str):
    if a digit or ')' is followed by '(': insert '*'

function eval(tokens) using two stacks (values, ops):
    apply * and / immediately (higher precedence)
    apply + and - after
    parentheses recurse / use a stack

function Calculator(str):
    str := insertImpliedMultiply(str)
    return evaluate(str)
*/

string insertStars(string s) {
    string out;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (i && (isdigit((unsigned char)s[i - 1]) || s[i - 1] == ')') && s[i] == '(') out += '*';
        if (i && s[i - 1] == ')' && isdigit((unsigned char)s[i])) out += '*';
        out += s[i];
    }
    return out;
}

long long applyOp(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}

int prec(char op) { return (op == '+' || op == '-') ? 1 : 2; }

void reduce(vector<long long>& vals, vector<char>& ops) {
    long long b = vals.back(); vals.pop_back();
    long long a = vals.back(); vals.pop_back();
    char op = ops.back(); ops.pop_back();
    vals.push_back(applyOp(a, b, op));
}

long long evalExpr(const string& s) {
    vector<long long> vals;
    vector<char> ops;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (isdigit((unsigned char)s[i])) {
            long long v = 0;
            while (i < (int)s.size() && isdigit((unsigned char)s[i])) {
                v = v * 10 + (s[i] - '0');
                ++i;
            }
            --i;
            vals.push_back(v);
        } else if (s[i] == '(') {
            ops.push_back('(');
        } else if (s[i] == ')') {
            while (!ops.empty() && ops.back() != '(') reduce(vals, ops);
            if (!ops.empty()) ops.pop_back();
        } else {
            while (!ops.empty() && ops.back() != '(' && prec(ops.back()) >= prec(s[i])) {
                reduce(vals, ops);
            }
            ops.push_back(s[i]);
        }
    }
    while (!ops.empty()) reduce(vals, ops);
    return vals.back();
}

string Calculator(string str) {
    return to_string(evalExpr(insertStars(str)));
}

int main() {
    string str;
    getline(cin, str);
    cout << Calculator(str) << endl;
    return 0;
}
