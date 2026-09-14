#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int bestSum = INT_MIN, bestLevel = 1, level = 1;
        while (!q.empty()) {
            int n = (int)q.size();
            long long sum = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > bestSum) {
                bestSum = (int)sum;
                bestLevel = level;
            }
            ++level;
        }
        return bestLevel;
    }
};
