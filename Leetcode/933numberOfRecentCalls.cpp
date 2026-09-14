#include <queue>
using namespace std;

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() = default;
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) q.pop();
        return (int)q.size();
    }
};
