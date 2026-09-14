#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Counting Minutes

Have the function CountingMinutes(str) take "hh:mmam-hh:mmpm" and return
how many minutes separate the two times. The interval may wrap midnight.

Examples:
  "9:00am-10:00am" -> 60
  "1:00pm-11:00am" -> 1320
  "12:30pm-12:00am" -> 690

Pseudocode
----------
function toMinutes(token):
    parse hh, mm, and am/pm
    if hh is 12: hh := 0
    if pm: hh := hh + 12
    return hh * 60 + mm

function CountingMinutes(str):
    split str on '-'
    start := toMinutes(left)
    finish := toMinutes(right)
    diff := finish - start
    if diff < 0: diff := diff + 24 * 60
    return diff
*/

int toMinutes(string t) {
    int hh = 0, mm = 0;
    char ap = 0;
    sscanf(t.c_str(), "%d:%d%c", &hh, &mm, &ap);
    ap = (char)tolower((unsigned char)ap);
    if (hh == 12) hh = 0;
    if (ap == 'p') hh += 12;
    return hh * 60 + mm;
}

int CountingMinutes(string str) {
    size_t dash = str.find('-');
    int start = toMinutes(str.substr(0, dash));
    int finish = toMinutes(str.substr(dash + 1));
    int diff = finish - start;
    if (diff < 0) diff += 24 * 60;
    return diff;
}

int main() {
    string str;
    getline(cin, str);
    cout << CountingMinutes(str) << endl;
    return 0;
}
