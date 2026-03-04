#include <bits/stdc++.h>
using namespace std;

int findNumber(int y, int x){
    if(y == x){
        int num = (y*y) - (y-1);
        return num;
    }
    int z = max(y, x);
    int num = (z-1) * (z-1);
    if(y%2 == 1 && y > x){
        
        return num + x;
    }
    if(y%2 == 0 && y > x){
        
        return num + 2 * y - x;
    }
    if(x%2 == 0 && y < x){
        
        return num + y;
    }
    if(x%2 == 1 && y < x){
        
        return num + 2 * x - y;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<int> number;
    while(n--){
        int y, x;
        cin >> y >> x;

        int rowCol = findNumber(y, x);
        cout << rowCol << endl;
    }

    return 0;
}