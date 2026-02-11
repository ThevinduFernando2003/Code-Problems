#include <stdio.h>
#include <iostream>
using namespace std;

void recursionFunction(int n){
    cout << n << endl;

    if (n == 1){  
        return; 
    }
    else if(n%2 == 1){
        n = n*3 + 1;
    }
    else{
        n = n/2;
        
    }

    recursionFunction(n);
}

int main(){
    int n;
    cin >> n;
    recursionFunction(n);
    return 0;
}
