#include <bits/stdc++.h>
using namespace std;

int main(){
    //children, weight
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int i = 0, j = n-1;
    int count = 0;
    while(i <= j){
        if(weights[i] + weights[j] <= x){
            i++;
            j--;
        }else{
            j--;
        }
        count++;   
    }

    cout << count << endl;
    
    return 0;
}