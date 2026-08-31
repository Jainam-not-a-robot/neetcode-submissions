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
    int recurse(TreeNode* root, int maxelem) {
        if (!root) return 0;
        int left = recurse(root->left, max(root->val, maxelem));
        int right = recurse(root->right, max(root->val, maxelem));
        return root->val >= maxelem ? left + right + 1 : left + right;
    }
    int goodNodes(TreeNode* root) {
        return recurse(root, INT_MIN);
    }
};
