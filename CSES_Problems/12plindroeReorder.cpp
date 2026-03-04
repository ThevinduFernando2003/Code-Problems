#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    unordered_map<char, int> frequency;
    for(char c : s){
        frequency[c]++;
    }

    int oddCount = 0;
    for(auto it : frequency){
        if(it.second % 2 != 0) oddCount++;
    }

    if(oddCount > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string half = "", middle = "";
    for(auto it : frequency){
        string part(it.second / 2, it.first);
        half += part;
        if(it.second %2 == 1){
            middle = it.first;
        }
    }

    string revHalf = half;
    reverse(revHalf.begin(), revHalf.end());

    cout << half + middle + revHalf << endl;
    return 0;
}