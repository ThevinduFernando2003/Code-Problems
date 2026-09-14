#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Simple Password

Return "true" if the password is valid:
  - length between 8 and 30
  - at least one uppercase letter
  - at least one digit
  - at least one punctuation symbol
  - does not contain the word "password" (any case)

Examples:
  "apple!M7"     -> true
  "passWord123!!" -> false

Pseudocode
----------
function SimplePassword(str):
    if length not in [8, 30]: return false
    if lowercase(str) contains "password": return false
    hasUpper := hasDigit := hasPunct := false
    for each ch:
        update the three flags
    return hasUpper and hasDigit and hasPunct
*/

string SimplePassword(string str) {
    if ((int)str.size() < 8 || (int)str.size() > 30) return "false";
    string low = str;
    for (char& ch : low) ch = (char)tolower((unsigned char)ch);
    if (low.find("password") != string::npos) return "false";
    bool up = false, dig = false, pun = false;
    for (unsigned char ch : str) {
        if (isupper(ch)) up = true;
        else if (isdigit(ch)) dig = true;
        else if (ispunct(ch)) pun = true;
    }
    return (up && dig && pun) ? "true" : "false";
}

int main() {
    string str;
    getline(cin, str);
    cout << SimplePassword(str) << endl;
    return 0;
}
