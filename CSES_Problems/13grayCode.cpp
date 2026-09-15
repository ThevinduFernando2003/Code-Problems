/*
CSES - Gray Code

n-bit Gray code list.

Pseudocode
----------
for i in 0 .. 2^n-1: print i xor (i>>1) as n bits
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> graycode(int n){
    vector<string> graycodes;
    int total = 1 << n;

    for(int i = 0; i < total; i++){
        int gray = i ^ (i >> 1);
        string binary = bitset<32>(gray).to_string();
        graycodes.push_back(binary.substr(32 - n));
    }
    return graycodes;
}

int main(){
    int n;
    cin >> n;
    
    vector<string> result = graycode(n);
    for(string code : result) {
        cout << code << endl;
    }
    return 0;
}