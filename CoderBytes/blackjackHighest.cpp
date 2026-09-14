#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Blackjack Highest

Have the function BlackjackHighest(strArr) score a hand.
Cards: two..ten, jack, queen, king (10), ace (1 or 11).
Return "below X", "blackjack X", or "above X" where X is the highest
card name. Ace is treated as highest only when it is counted as 11.

Examples:
  {"four", "ace", "ten"} -> "below ten"
  {"ace", "queen"}       -> "blackjack ace"

Pseudocode
----------
function BlackjackHighest(cards):
    hard := sum of non-ace ranks  (face = 10)
    aces := count of aces
    total := hard + aces                  // every ace as 1
    usedSoftAce := false
    if aces > 0 and total + 10 <= 21:
        total := total + 10
        usedSoftAce := true

    highest := the card with the largest rank
               (ace wins only if usedSoftAce)
    if total == 21: return "blackjack " + highest
    if total > 21:  return "above " + highest
    return "below " + highest
*/

int rankValue(const string& c) {
    if (c == "ace") return 11;
    if (c == "two") return 2;
    if (c == "three") return 3;
    if (c == "four") return 4;
    if (c == "five") return 5;
    if (c == "six") return 6;
    if (c == "seven") return 7;
    if (c == "eight") return 8;
    if (c == "nine") return 9;
    return 10;
}

string BlackjackHighest(vector<string> cards) {
    int hard = 0, aces = 0;
    for (auto& c : cards) {
        if (c == "ace") ++aces;
        else hard += rankValue(c);
    }
    int total = hard + aces;
    bool soft = false;
    if (aces && total + 10 <= 21) {
        total += 10;
        soft = true;
    }
    string highest;
    int best = -1;
    for (auto& c : cards) {
        int r = (c == "ace") ? (soft ? 14 : 1) : rankValue(c);
        if (r > best) {
            best = r;
            highest = c;
        }
    }
    string prefix = total == 21 ? "blackjack" : (total > 21 ? "above" : "below");
    return prefix + " " + highest;
}

int main() {
    int n;
    cin >> n;
    vector<string> cards(n);
    for (int i = 0; i < n; ++i) cin >> cards[i];
    cout << BlackjackHighest(cards) << endl;
    return 0;
}
