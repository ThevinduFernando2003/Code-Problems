#include <bits/stdc++.h>
using namespace std;

int main(){
    //length, num lights
    int x, y;
    cin >> x >> y;

    vector<int> lights;
    lights.push_back(0);
    lights.push_back(x);

    for(int i = 0; i < y; i++){
        int pos;
        cin >> pos;
        lights.push_back(pos);
        sort(lights.begin(), lights.end());

        vector<int> lengths;
        for(int j = 0; j < lights.size()-1; j++){
            lengths.push_back(lights[j+1] - lights[j]);
        }
        int max = *max_element(lengths.begin(), lengths.end());
        cout << max << " ";
    
    }
    cout << endl;
    return 0;
}