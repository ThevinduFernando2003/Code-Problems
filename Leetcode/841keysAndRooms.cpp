#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> seen(rooms.size());
        stack<int> st;
        st.push(0);
        seen[0] = 1;
        int left = (int)rooms.size() - 1;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            for (int v : rooms[u]) {
                if (!seen[v]) {
                    seen[v] = 1;
                    --left;
                    st.push(v);
                }
            }
        }
        return left == 0;
    }
};
