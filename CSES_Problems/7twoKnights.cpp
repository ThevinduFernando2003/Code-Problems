/*
CSES - Two Knights

Ways to place two knights on kxk so they do not attack, for k=1..n.

Pseudocode
----------
total pairs := C(k^2, 2)
attacking := 2*(k-1)*(k-2)*2
answer := total - attacking
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n+1; i++){
        long long total = (i*i) * (i*i - 1) / 2;
        long long attack = 4 * (i-1) * (i-2);
        cout << total - attack << endl;
    }
    return 0;

}