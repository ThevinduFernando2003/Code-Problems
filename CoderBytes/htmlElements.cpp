#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — HTML Elements

Have the function HTMLElements(str) check nesting of <b> <i> <em> <div> <p>.
Return "true" if every tag matches. Otherwise return the first opening
tag name that does not match its closer.

Examples:
  "<div><b><p>hello world</p></b></div>" -> true
  "<div><i>hello</i>world</b>"           -> div

Pseudocode
----------
function HTMLElements(str):
    stack := empty
    scan str for tags <name> and </name>
    if opening: push name
    if closing:
        if stack is empty or top != name:
            return (stack empty ? name : top)
        pop
    if stack not empty: return stack.top
    return true
*/

string HTMLElements(string str) {
    vector<string> st;
    for (int i = 0; i < (int)str.size(); ++i) {
        if (str[i] != '<') continue;
        int j = (int)str.find('>', i);
        if (j == (int)string::npos) break;
        string tag = str.substr(i + 1, j - i - 1);
        bool close = !tag.empty() && tag[0] == '/';
        string name = close ? tag.substr(1) : tag;
        if (close) {
            if (st.empty() || st.back() != name) return st.empty() ? name : st.back();
            st.pop_back();
        } else {
            st.push_back(name);
        }
        i = j;
    }
    if (!st.empty()) return st.back();
    return "true";
}

int main() {
    string str;
    getline(cin, str);
    cout << HTMLElements(str) << endl;
    return 0;
}
