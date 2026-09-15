/*
CSES - Towers

Greedy: put cube on the leftmost tower that is strictly taller.
Number of towers needed.

Pseudocode
----------
multiset of top cubes
upper_bound(cube); if none, new tower, else replace that top
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int tower;
    vector<int> array(n);
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    multiset<int> towers;

    for(int num : array){
        auto it = towers.upper_bound(num);
        if(it != towers.end()){
            towers.erase(it);
        }
        towers.insert(num);
    }

    cout << towers.size() << endl;
    return 0;
}