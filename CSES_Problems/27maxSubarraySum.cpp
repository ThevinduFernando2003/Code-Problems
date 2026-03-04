#include <bits/stdc++.h>
using namespace std;

int maxArraySum(vector<int>& array){
    int maxSum = array[0];
    int currentSum = array[0];

    for(int i = 1; 1 < array.size(); i++){
        currentSum = max(array[i], currentSum + array[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main(){
    int n;
    cin >> n;

    vector<int> array(n);
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << maxArraySum(array) << endl;
    return 0;
}