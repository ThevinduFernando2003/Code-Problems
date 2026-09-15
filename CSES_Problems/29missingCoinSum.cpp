/*
CSES - Missing Coin Sum

Smallest amount that cannot be formed with the coins.

Pseudocode
----------
sort coins
res := 1
for coin <= res: res += coin
print res
*/

#include <bits/stdc++.h>
using namespace std;
//missing coin sum
int main(){
    int n;
    cin >> n;

    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    long long small = 1;

    for(int i = 0; i < n; i++){
        if(coins[i] > small){
            break;
        }
        small += coins[i];
    }

    cout << small << endl;
    return 0;
}