#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> rounds(n);
    for(int i = 0; i < n; i++){
        cin >> rounds[i];
    }

    int num = 1;
    int round = 0;
    while(num <= n){
        for(int j = 0; j < n; j++){
            if(rounds[j] == num){
                num++;
            }
        }
        round++;
    }

    cout << round << endl;
    return 0;
}