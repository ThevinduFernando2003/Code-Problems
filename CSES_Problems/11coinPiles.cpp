/*
CSES - Coin Piles

From piles (a,b) you may remove (1,2) or (2,1). Can you empty both?

Pseudocode
----------
a+b divisible by 3 and min(a,b)*2 >= max(a,b)
*/

#include <bits/stdc++.h>
using namespace std;

void output(int x, int y){
    if(x % 2 == 0 || x % 3 == 0){
        if(y % 2 == 0 || y % 3 == 0){
            cout << "YES" << endl;
            return;
        }
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    int count;
    cin >> count;
    int x, y;
    for(int i = 1; count >= i; i++){
        cin >> x >> y;
        output(x, y);
    }
    return 0;
}