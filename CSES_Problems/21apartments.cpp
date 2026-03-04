#include <bits/stdc++.h>
using namespace std;

int main(){
    //applicants, apartments, difference
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> desire(n);
    for(int i = 0; i < n; i++){
        cin >> desire[i];
    }

    vector<int> apartments(m);
    for(int j = 0; j < m; j++){
        cin >> apartments[j];
    }

    sort(desire.begin(), desire.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, count = 0;
    while(i < n && j < m){
        if(abs(apartments[j]-desire[i]) <= k){
            count++;
            i++;
            j++;
        }else if(apartments[j] < desire[i] - k){
            j++;
        }else{
            i++;
        }
    }

    cout << count << endl;

    return 0;
}
