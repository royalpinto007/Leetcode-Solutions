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
    vector<int> answer;
    
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        // Visit the root first, then the left subtree, then the right subtree.

        answer.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return answer;
    }
};