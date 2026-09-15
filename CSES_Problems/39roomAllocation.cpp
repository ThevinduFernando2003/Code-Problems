#include <bits/stdc++.h>
using namespace std;

/*
CSES - Room Allocation

Assign the fewest rooms so that overlapping stays get different rooms.

Pseudocode
----------
sort customers by arrival
min-heap of (departure, roomId) for occupied rooms
for each customer:
    if the earliest departure < this arrival:
        reuse that room
    else:
        open a new room
print max rooms used, then the room of each customer
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occ;
    vector<int> room(n);
    int used = 0;
    for (auto [l, r, id] : a) {
        if (!occ.empty() && occ.top().first < l) {
            int rid = occ.top().second;
            occ.pop();
            room[id] = rid;
            occ.push({r, rid});
        } else {
            room[id] = ++used;
            occ.push({r, used});
        }
    }
    cout << used << "\n";
    for (int i = 0; i < n; i++) cout << room[i] << " \n"[i == n - 1];
    return 0;
}
