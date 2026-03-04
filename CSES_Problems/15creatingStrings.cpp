#include <bits/stdc++.h>
using namespace std;

/*long long factorial(int n){
    long long res = 1;
    for(int i = 2; i < n; i++){
        res *= i;
    }
    return res;
}

long long permutation(string s){
    unordered_map<char, int> frequency;
    for(char c : s){
        frequency[c]++;
    }

    long long total = factorial(s.length());
    for(auto[ch, count] : frequency){
        total /= factorial(count);
    }

}



int main(){
    string input;
    cin >> input;
    
    permutation(input);
    return 0;   
}*/

int main(){
    string s;
    cin >> s;

    sort(s.begin(),s.end());
    set<string> permutations;

    do{
        permutations.insert(s);
    }while(next_permutation(s.begin(), s.end()));

    cout << permutations.size() << endl;
    for(const string& perm : permutations){
        cout << perm << endl;
    }

    return 0;
}