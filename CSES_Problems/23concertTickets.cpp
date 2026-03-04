#include <bits/stdc++.h>
using namespace std;

int main(){
    //tickets, customers
    int n, m;
    cin >> n >> m;

    vector<int> tickets(n);
    for(int i = 0; i < n; i++){
        cin >> tickets[i];
    }
    sort(tickets.begin(), tickets.end());

    
    for(int j = 0; j < m; j++){
        int price;
        cin >> price;

        int low = 0, high = tickets.size() - 1;
        int best = -1;

        //binary search
        while(low <= high){
            int mid = (low + high) / 2;
            if(tickets[mid] <= price){
                best = mid;
                low = mid+1;
            }else{
                high = mid - 1;
            }
        }
        //print result
        if(best == -1){
            cout << -1 << endl;
        }else{
            cout << tickets[best] << endl;
            tickets.erase(tickets.begin() + best); //remove ticket
        }
    }

    return 0;
}