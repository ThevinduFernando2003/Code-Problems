/*
CSES - Collecting Numbers

Count rounds to collect 1..n in order.

Pseudocode
----------
record position of each value
rounds := 1
for x from 2 to n:
    if pos[x] < pos[x-1]: rounds++
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> rounds(n);
    for(int i = 0; i < n; i++){
        cin >> rounds[i];
    }

    int num = 1;
    int round = 0;
    while(num <= n){
        for(int j = 0; j < n; j++){
            if(rounds[j] == num){
                num++;
            }
        }
        round++;
    }

    cout << round << endl;
    return 0;
}