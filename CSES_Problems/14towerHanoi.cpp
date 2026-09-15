/*
CSES - Tower of Hanoi

Print the moves to move n disks from peg 1 to peg 3.

Pseudocode
----------
hanoi(n, a, b, c):
    hanoi(n-1, a, c, b)
    print a c
    hanoi(n-1, b, a, c)
*/

#include <bits/stdc++.h>
using namespace std;

int towerofHanoi(int n, int from, int via, int to, vector<pair<int,int>>& moves){
    if(n==1){
        moves.push_back({from, to});
        return;
    }

    towerofHanoi(n-1,from,to,via,moves);
    moves.push_back({from, to});

    towerofHanoi(n-1, via, from, to, moves);
    
}

int main(){
    int n;
    cin >> n ;
    vector<pair<int,int>> moves;
    towerofHanoi(n,1, 2, 3, moves);

    cout << moves.size() << endl;
    for(auto[a,b] : moves){
        cout << a << " " << b << endl;
    }
    return 0;
}
