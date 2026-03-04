#include <bits/stdc++.h>
using namespace std;

int main(){
    //josephus
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i <= n; i++){
        nums.push_back(i);
    }

    for(int i = 1; i < n; i += 2){
        if(i == n-1){
            i = 0;
        }
        cout << nums[i] << " ";
    }
    cout << endl;
    

    return 0;
}