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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        vector<int> ans;
        
        stk.push(cur);
        
        do{
            cur = stk.top();
            
            //go to its leftmost child
            TreeNode* tmp = cur ? cur->left : NULL;
            while(tmp){
                stk.push(tmp);
                tmp = tmp->left;
            }
            
            //if it has left child, process leftmost child first
            cur = stk.top(); stk.pop();
            if(cur) ans.push_back(cur->val);
            
            //cut current node and its parent, 
            //so current node won't be traversed again
            if(stk.size() > 0) stk.top()->left = NULL;
            
            //deal with right child
            if(cur && cur->right) stk.push(cur->right);
        }while(!stk.empty());
        
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> ans;
    
//     void inorderTraversalR(TreeNode* root){
//         if(!root) return;
//         if(root->left){
//             inorderTraversal(root->left);
//         }
//         ans.push_back(root->val);
//         if(root->right){
//             inorderTraversal(root->right);
//         }
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         inorderTraversalR(root);
//         return ans;
//     }
// };