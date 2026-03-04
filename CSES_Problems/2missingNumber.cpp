#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/*
//linear search method
void findNumber(vector<int>& nums, int n){
    for(int i = 0; i < n; i++){
        bool found = false;

        for(int j = 0; j < n-1; j++){
            if(j == nums[j]){
                found = true;
                break;
            }
        }
        if(!found){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n; //input the numers num

    vector<int> nums(n-1);
    for(int i=0; i < n-1; i++){
        cin >> nums[i];
    }
    int missingNumber = findNumber(nums, n);
    cout << missingNumber << endl;
    return 0;
}
*/


/*
//linked list method
#include <list>

int findNumber(list<int>& nums, int n){
    for(int i = 0; i < n; i++){
        bool found = false;
        for(int num: nums){
            if(num==i){
                found = true;
                break;
            }
        }
        if (!found){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    list<int> nums;
    for(int i = 0; i < n-1; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int missingNumber = findNumber(nums, n);
    cout << missingNumber << endl;
    return 0;
}
*/


//optimized method
//get the real sum and the expected sum and difference is the missing number
int findNumber(vector<int>& nums, int n){
    int expectedSum = (n* (n-1))/2;
    int actualSum = 0;

    for (int num : nums){
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums;
    for(int i = 0; i < n-1; i++){
        cin >> nums[i];
    }

    int missingNumber = findNumber(nums, n);
    cout << missingNumber << endl;
    return 0;
}