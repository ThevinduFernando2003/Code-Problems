#include <bits/stdc++.h>
using namespace std;

int numberMoves(int n, vector<int> nums){
    int moves;
    for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1]){
            moves += nums[i] - nums[i+1];
            nums[i+1] = nums[i];
        }
    }
    return moves;
}

int main(){
    int n;
    vector<int> nums;
    cin >> n ;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int moves = numberMoves(n, nums);

    cout << moves << endl;

    return 0;
}