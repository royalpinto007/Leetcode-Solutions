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


/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> iStack;
        iStack.push(root);
        
        // Note that we add currNode's right child to the stack first.
        while (!iStack.empty()) {
            TreeNode* currNode = iStack.top();
            iStack.pop();
            if (currNode != nullptr) {
                answer.push_back(currNode -> val);
                iStack.push(currNode -> right);
                iStack.push(currNode -> left);
            }
        }
        
        return answer;
    }
};
*/

/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        TreeNode* curr = root;
        TreeNode* last;
        
        while (curr != nullptr) {
            // If there is no left child, go for the right child.
            // Otherwise, find the last node in the left subtree. 
            if (curr->left == nullptr) {
                answer.push_back(curr->val);
                curr = curr->right;
            } else {
                last = curr->left;
                while (last->right != nullptr && last->right != curr) {
                    last = last->right;
                }
                
                // If the last node is not modified, we let 
                // 'curr' be its right child. Otherwise, it means we 
                // have finished visiting the entire left subtree.
                if (last->right == nullptr) {
                    answer.push_back(curr->val);
                    last->right = curr;
                    curr = curr->left;
                } else {
                    last->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        
        return answer;
    }
};
*/