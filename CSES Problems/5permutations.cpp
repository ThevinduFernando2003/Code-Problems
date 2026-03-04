#include <bits/stdc++.h>
using namespace std;
#random commit
int permutation(int n){
    vector<int> nums;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
        return 0;
    }
    else if (n > 3){
        for(int i = 2; i <= n; i+=2 ){
            cout << i << " ";
        }
        for(int i = 1; i <= n; i+=2){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

int main(){
    int n;
    cin >> n;
    int nums = permutation(n);
    return 0;
}
