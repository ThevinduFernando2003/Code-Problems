#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> weights(n);
    //int weights[n];
    long long total = 0;
    for(int i = 0; i < n; i++){
        cin >> weights[i];
        total += weights[i];
    }
    long long minDiff = LLONG_MAX;


    for(int mask = 0; mask < (1<<n); mask++){
        long long group1 = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                group1 += weights[i];
            }
        }
        long long group2 = total - group1;
        minDiff = min(minDiff, abs(group1 - group2));
    }

    cout << minDiff << endl;
     
    return 0;
}