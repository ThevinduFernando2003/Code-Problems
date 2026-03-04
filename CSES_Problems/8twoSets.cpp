#include <bits/stdc++.h>
using namespace std;

int twoSets(int total, int n){
    vector<int> set1, set2;
    int target = total / 2;
    for(int i = n; i >= 1; i--){
        if(target >= i){
            set1.push_back(i);
            target -= i;
        }
        if(target < i){
            set2.push_back(i);
        }
    }
    cout << set1.size() << endl;
    for(int num : set1){
        cout << num << " ";
    }
    cout << set2.size() << endl;
    for(int num : set2){
        cout << num << " ";
    }
    return 0;
}

int totalSum(int n){

    int num = 0;
    num = n*(n+1) / 2;
    if(num%2 == 1){
        cout << "NO" << endl;
        return 0;
    }
    if(num%2 == 0){
        cout << "YES" << endl;
        twoSets(num, n);       
    }

    return -1;
}

int main(){
    int n;
    cin >> n;
    totalSum(n);
    return 0;
}