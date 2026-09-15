/*
CSES - Chessboard and Queens

Ways to place 8 queens on a reserved chessboard.

Pseudocode
----------
backtrack row by row
skip reserved squares, used columns, and both diagonals
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    vector<vector<int>> chessboard;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> c;
            if(c == '.'){
                chessboard[i][j] == 0;
            }else{
                chessboard[i][j] == 1;
            }
        }

    }
    return 0;
}