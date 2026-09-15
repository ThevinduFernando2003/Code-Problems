/*
CSES - Movie Festival

Maximum movies with no overlap.

Pseudocode
----------
sort by ending time
take a movie if it starts after the last taken ending
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    //movies
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        movies[i] = {b, a};
    }
    sort(movies.begin(), movies.end());
    
    return 0;
}