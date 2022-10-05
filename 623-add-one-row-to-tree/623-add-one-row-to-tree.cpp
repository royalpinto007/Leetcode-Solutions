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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        int curr_depth=1;
        if(d==1) {
            TreeNode* temp = new TreeNode( v );
            temp->left=root;
            
            return temp;
        }
        helper(root,v,d,curr_depth);
        
        return root;
    }
    
    void helper(TreeNode* root, int& v ,int & d ,int & curr_depth) {
        if(root==NULL)
            return ;
        
        if(curr_depth<d-1) {
            curr_depth++;
            helper(root->left,v,d,curr_depth);
            helper(root->right,v,d,curr_depth);
            curr_depth--;
        }
        
        if(curr_depth==(d-1)) {
            TreeNode* temp_left=new TreeNode(v);
            TreeNode* temp_right=new TreeNode(v);
            
            temp_left->left=root->left;
            temp_right->right=root->right;
            
            root->left=temp_left;
            root->right=temp_right;
            
        }
    }
};