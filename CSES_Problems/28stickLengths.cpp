#include <bits/stdc++.h>
using namespace std;

//Another method sort the sticks lengths and get the middle one and
//to the middle element get the others lengths

int main(){
    int n;
    cin >> n;
    vector<int> lengths(n);
    for(int i = 0; i < n; i++){
        cin >> lengths[i];
    }

    vector<int> minSum(n);
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n && i != j; j++){
            sum += abs(lengths[i] - lengths[j]);
        }
        minSum[i] = sum;
    }

    int min = minSum[0];
    for(int i = 1; i < n; i++){
        if(minSum[i] < min){
            min = minSum[i];
        }
    }
    cout << min << endl;
    return 0;
}