#include <bits/stdc++.h>
using namespace std;

int main(){
    //customers
    int n;
    cin >> n;

    vector<int> times(n*2);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        for(int j = a; j < b; j++){
            times.push_back(j);
        }
    }
    unordered_map<int, int> freq;
    int maxFreq = 0;

    for(int time : times){
        freq[time]++;
        if(freq[time] > maxFreq){
            maxFreq = freq[time];
        }
    }
    cout << maxFreq << endl;

    return 0;
}