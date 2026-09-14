#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Most Free Time

strArr is a list of events "hh:mmAM-hh:mmPM". Return the longest idle
gap between the earliest start and the latest end, formatted HH:MM.
Events may be unsorted. There are at least three events.

Examples:
  {"12:15PM-02:00PM", "09:00AM-10:00AM", "10:30AM-12:00PM"} -> "00:30"
  {"12:15PM-02:00PM", "09:00AM-12:11PM", "02:02PM-04:00PM"} -> "00:04"

Pseudocode
----------
function toMinutes(token): convert 12-hour time to minutes from midnight
function MostFreeTime(events):
    parse each start/end
    sort by start
    best := 0
    for i from 1 to last:
        best := max(best, start[i] - end[i-1])
    return format best as HH:MM
*/

int stamp(string t) {
    int hh = 0, mm = 0;
    char ap = 0;
    sscanf(t.c_str(), "%d:%d%c", &hh, &mm, &ap);
    ap = (char)toupper((unsigned char)ap);
    if (hh == 12) hh = 0;
    if (ap == 'P') hh += 12;
    return hh * 60 + mm;
}

string MostFreeTime(vector<string> events) {
    vector<pair<int, int>> iv;
    for (auto& e : events) {
        size_t d = e.find('-');
        iv.push_back({stamp(e.substr(0, d)), stamp(e.substr(d + 1))});
    }
    sort(iv.begin(), iv.end());
    int best = 0;
    for (int i = 1; i < (int)iv.size(); ++i) best = max(best, iv[i].first - iv[i - 1].second);
    char buf[8];
    snprintf(buf, sizeof(buf), "%02d:%02d", best / 60, best % 60);
    return buf;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> events(n);
    for (int i = 0; i < n; ++i) getline(cin, events[i]);
    cout << MostFreeTime(events) << endl;
    return 0;
}
