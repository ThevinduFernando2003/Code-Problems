#include <algorithm>
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
    int best = 0;
    void dfs(TreeNode* node, bool goLeft, int len) {
        if (!node) return;
        best = max(best, len);
        if (goLeft) {
            dfs(node->left, false, len + 1);
            dfs(node->right, true, 1);
        } else {
            dfs(node->right, true, len + 1);
            dfs(node->left, false, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return best;
    }
};
