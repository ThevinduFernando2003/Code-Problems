#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int tower;
    vector<int> array(n);
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    multiset<int> towers;

    for(int num : array){
        auto it = towers.upper_bound(num);
        if(it != towers.end()){
            towers.erase(it);
        }
        towers.insert(num);
    }

    cout << towers.size() << endl;
    return 0;
}