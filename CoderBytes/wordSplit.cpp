#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Word Split

strArr[0] is a word. strArr[1] is a comma-separated dictionary.
If the word is exactly two dictionary words glued together, return
those words as "left,right". Otherwise "not possible".

Examples:
  {"baseball", "a,all,b,ball,bas,base,cat,code,d,e,quit,z"} -> "base,ball"
  {"abcgefd", "a,bb,cc,d,ee,f,ggg"} -> "not possible"

Pseudocode
----------
function WordSplit(arr):
    word := arr[0]
    dict := set of tokens in arr[1]
    for split from 1 to length-1:
        left := word[0..split)
        right := word[split..]
        if both are in dict: return left + "," + right
    return "not possible"
*/

string WordSplit(vector<string> arr) {
    string word = arr[0];
    unordered_set<string> dict;
    stringstream ss(arr[1]);
    string tok;
    while (getline(ss, tok, ',')) dict.insert(tok);
    for (int i = 1; i < (int)word.size(); ++i) {
        string left = word.substr(0, i), right = word.substr(i);
        if (dict.count(left) && dict.count(right)) return left + "," + right;
    }
    return "not possible";
}

int main() {
    string word, dict;
    getline(cin, word);
    getline(cin, dict);
    cout << WordSplit({word, dict}) << endl;
    return 0;
}
