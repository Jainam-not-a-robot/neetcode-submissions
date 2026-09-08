/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int recurse(TreeNode* root, int maxim) {
        if (!root) return 0;
        int left = recurse(root->left, max(maxim, root->val));
        int right = recurse(root->right, max(maxim, root->val));
        return root->val >= maxim ? 1 + left + right : left + right;
    }
    int goodNodes(TreeNode* root) {
        return recurse(root, INT_MIN);
    }
};
