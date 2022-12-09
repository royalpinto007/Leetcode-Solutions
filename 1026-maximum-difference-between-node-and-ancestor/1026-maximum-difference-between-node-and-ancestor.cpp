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
    int maxAncestorDiff(TreeNode* root) {
        return visit(root, root->val, root->val);
    }
    
    int visit(TreeNode* root, int curr_min, int curr_max) {
        if (root==NULL) {
            return curr_max - curr_min;
        }
        curr_max = max(root->val, curr_max);
        curr_min = min(root->val, curr_min);
        int left_diff = visit(root->left, curr_min, curr_max);
        int right_diff = visit(root->right, curr_min, curr_max);
        return max(left_diff, right_diff);
    }
};