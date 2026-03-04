#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    list<int> num;
    for(int i = 1; i < x; i++){
        num.push_back(i);
    }

    auto it = num.begin();
    while(num.size() > 1){
        ++it;
        if(it == num.end()) it = num.begin();
        it = num.erase(it); 
        if(it == num.end()) it = num.begin();
    }
    cout << num.front() << endl;

    return 0;
}