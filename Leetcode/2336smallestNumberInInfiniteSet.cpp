#include <set>
using namespace std;

class SmallestInfiniteSet {
    int next = 1;
    set<int> added;
public:
    int popSmallest() {
        if (!added.empty()) {
            int x = *added.begin();
            added.erase(added.begin());
            return x;
        }
        return next++;
    }
    void addBack(int num) {
        if (num < next) added.insert(num);
    }
};
