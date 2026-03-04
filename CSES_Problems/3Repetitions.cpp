#include <iostream>
#include <unordered_map>

using namespace std;

//using dictionary/unordered map
int longestRepetition(string n){
    unordered_map<char, int> countMap;
    int maxCount = 0;
    int currentCount = 0;
    char prevChar = '\0';

    for(char c: n){
        if(c == prevChar){
            currentCount += 1;
        }
        else{
            currentCount = 1;
            prevChar = c;
        }
        countMap[c] = max(countMap[c], currentCount);
        maxCount = max(maxCount, countMap[c]);
    }

    return maxCount;
}

int main(){
    string n;
    cin >> n;

    int longest = longestRepetition(n);

    cout << longest << endl;
    return 0;
}




//optiized version
int longestRepetition(string n){
    int maxCount = 0; 
    int currentCount = 0;

    for(size_t i = 1; i < n.length(); i++){
        if(n[i] == n[i-1]){
            currentCount ++;
        }else{
            currentCount = 1;
        }
        //compare the new char count and the old max count
        maxCount = max(maxCount, currentCount);
    }

    return maxCount;
}

int main(){
    string n;
    cin >> n;

    int longest = longestRepetition(n);

    cout << longest << endl;
    return 0;
}