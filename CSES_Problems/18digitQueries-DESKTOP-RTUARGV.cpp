#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++){
        cin >> array[i]; 
    }
    int maximum = *max_element(array.begin(), array.end());

    string nums = "";
    for(int i = 1; i <= maximum; i++){
        nums += to_string(i);
    }
    for(int i = 0; i < n; i++){
        char number = nums[array[i]];
        cout << number << endl;
    }

    return 0;
}