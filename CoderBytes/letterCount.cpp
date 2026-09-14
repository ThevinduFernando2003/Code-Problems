#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Letter Count

Have the function LetterCount(str) return the first word that contains
the greatest number of repeated letters (max frequency of any one letter).
If no letter repeats in any word, return "-1".

Examples:
  "Hello apple pie" -> "Hello"
  "No words"        -> "-1"

Pseudocode
----------
function repeats(word):
    count letters ignoring case
    return the largest frequency

function LetterCount(str):
    bestWord := "-1"
    best := 1
    for each word in str:
        r := repeats(word)
        if r > best:
            best := r
            bestWord := word
    return bestWord
*/

int repeats(const string& word) {
    int freq[256] = {};
    int best = 0;
    for (unsigned char ch : word) {
        if (!isalpha(ch)) continue;
        best = max(best, ++freq[tolower(ch)]);
    }
    return best;
}

string LetterCount(string str) {
    stringstream ss(str);
    string word, bestWord = "-1";
    int best = 1;
    while (ss >> word) {
        int r = repeats(word);
        if (r > best) {
            best = r;
            bestWord = word;
        }
    }
    return bestWord;
}

int main() {
    string str;
    getline(cin, str);
    cout << LetterCount(str) << endl;
    return 0;
}
