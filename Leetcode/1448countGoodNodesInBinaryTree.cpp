#include <algorithm>
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
    int dfs(TreeNode* node, int best) {
        if (!node) return 0;
        int good = node->val >= best;
        best = max(best, node->val);
        return good + dfs(node->left, best) + dfs(node->right, best);
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};
