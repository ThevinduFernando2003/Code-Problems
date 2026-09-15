/*
CSES - Josephus Problem I

Every other remaining child is removed, starting from 1.

Pseudocode
----------
queue/list of children
while more than one: pop, skip (push back), pop and print
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    list<int> num;
    for(int i = 1; i < x; i++){
        num.push_back(i);
    }

    auto it = num.begin();
    while(num.size() > 1){
        ++it;
        if(it == num.end()) it = num.begin();
        it = num.erase(it); 
        if(it == num.end()) it = num.begin();
    }
    cout << num.front() << endl;

    return 0;
}