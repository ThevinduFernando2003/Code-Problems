/*
CSES - Collecting Numbers II

After each swap of two positions, reprint the number of rounds.

Pseudocode
----------
keep pos[] of each value
a swap changes at most the pairs (v,v+1) for the two values
recompute those pairs before and after
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        //swap x, y
        //int temp = nums[x];
        //nums[x] = nums[y];
        //nums[y] = temp;
        swap(nums[x], nums[y]);
        //count rounds
        int num = 1;
        int round = 0;
        
        while(num <= n){
            for(int j = 0; j < n; j++){
                if(nums[j] == num){
                    num++;
                }
            }
            round++;
        }
        cout << round << endl;
    }
    return 0;
}