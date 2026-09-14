#include <unordered_map>
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
    int dfs(TreeNode* node, long long need, long long prefix, unordered_map<long long, int>& freq) {
        if (!node) return 0;
        prefix += node->val;
        int ans = freq[prefix - need];
        ++freq[prefix];
        ans += dfs(node->left, need, prefix, freq);
        ans += dfs(node->right, need, prefix, freq);
        --freq[prefix];
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> freq;
        freq[0] = 1;
        return dfs(root, targetSum, 0, freq);
    }
};
