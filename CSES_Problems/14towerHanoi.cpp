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
