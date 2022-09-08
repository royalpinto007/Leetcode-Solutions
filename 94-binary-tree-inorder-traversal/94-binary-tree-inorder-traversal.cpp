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
        vector<int> ans;
        TreeNode *cur = root, *pre;
        
        while(cur){
            if(cur->left){
                pre = cur->left;
                while(pre->right){
                    pre = pre->right;
                }
                //pre->right is now cur's rightmost child
                //it doesn't have right child
                //pre is the parent of cur's rightmost child
                pre->right = cur;
                TreeNode* tmp = cur;
                //current root becomes its left child
                cur = cur->left;
                //cur original root's left subtree
                tmp->left = nullptr;
            }else{
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         stack<TreeNode*> stk;
//         TreeNode* cur = root;
//         while(cur || !stk.empty()){
//             //if cur is nullptr, it's ok, because it will later be stk.top()
//             while(cur){
//                 stk.push(cur);
//                 cur = cur->left;
//             }
//             cur = stk.top(); stk.pop();
//             ans.push_back(cur->val);
//             //it's fine if cur->right is nullptr
//             cur = cur->right;
//         }
        
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         stack<TreeNode*> stk;
//         TreeNode* cur;
        
//         stk.push(root);
        
//         while(!stk.empty()){
//             cur = stk.top();
//             while(cur && cur->left){
//                 stk.push(cur->left);
//                 cur = cur->left;
//             }
//             cur = stk.top(); stk.pop();
//             if(cur) ans.push_back(cur->val);
//             if(stk.size() > 0) stk.top()->left = nullptr;
//             if(cur && cur->right) stk.push(cur->right);
//         }
        
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> stk;
//         TreeNode* cur = root;
//         vector<int> ans;
        
//         stk.push(cur);
        
//         do{
//             cur = stk.top();
            
//             //go to its leftmost child
//             TreeNode* tmp = cur ? cur->left : NULL;
//             while(tmp){
//                 stk.push(tmp);
//                 tmp = tmp->left;
//             }
            
//             //if it has left child, process leftmost child first
//             cur = stk.top(); stk.pop();
//             if(cur) ans.push_back(cur->val);
            
//             //cut current node and its parent, 
//             //so current node won't be traversed again
//             if(stk.size() > 0) stk.top()->left = NULL;
            
//             //deal with right child
//             if(cur && cur->right) stk.push(cur->right);
//         }while(!stk.empty());
        
//         return ans;
//     }
// };
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