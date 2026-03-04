#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    set<int> songs;
    int count = 0;
    for(int i = 0; i < n; i++){
        int x;
        
        cin >> x;
        if(songs.find(x) != songs.end()){
            if(songs.size() > count){
                count = songs.size();
            }
            songs.clear();
        }
        songs.insert(x);  
        
    }
    if(songs.size() > count){
        count = songs.size();
    }
    cout << count << endl;
    return 0;
}