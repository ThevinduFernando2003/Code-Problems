/*
CSES - Digit Queries

k-th digit in the infinite string 123456789101112...

Pseudocode
----------
count how many digits are contributed by 1-digit, 2-digit, ... numbers
land in that block, pick the number and the digit inside it
*/

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