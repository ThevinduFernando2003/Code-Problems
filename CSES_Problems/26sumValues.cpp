/*
CSES - Sum of Two Values

Two indices that sum to x, or IMPOSSIBLE.

Pseudocode
----------
map value -> index
for each a[i], look up x-a[i]
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int sum = arr[i] + arr[j];
            if(sum == x){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}