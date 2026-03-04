#include <bits/stdc++.h>
using namespace std;

/*bool isPrime(int n){
    if(n < 2) return false;

    for(int i = 2; i * i <= n; i++){
        if(n%i == 0){
            return false;
        }

        
    }
    return true;
}

long long getPrime(long long num){
    long long sum = 0, n=0;
    while(n < num){
        n++;
        if(isPrime(n)){
            sum += n;
        }
    }
    return sum;
}

int main(){
    long long num = 2000000;
    long long sum = getPrime(num);
    cout << sum << endl;

    return 0;
}*/

int main(){
    const int limit = 2000000;
    vector<bool> isPrime(limit, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i *i < limit; i++){
        if(isPrime[i]){
            for(int j = i*i; j < limit; j+= i){
                isPrime[j] = false;
            }
        }
    }

    long long sum = 0;
    for(int i = 2; i < limit; i++){
        if(isPrime[i]) sum += i;
    }

    cout << sum << endl;

    return 0;
}
