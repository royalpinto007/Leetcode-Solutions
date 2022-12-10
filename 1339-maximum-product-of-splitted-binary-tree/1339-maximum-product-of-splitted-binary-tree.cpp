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
    long long int currsum = 0;
    long long int totalsum = 0;long long int maxi = 0;
    long long int m = 1e9 + 7;
    void Traversal(TreeNode* root) // To calculate Total sum
    {
        if(root==NULL)
        {
            return;
        }
        Traversal(root->left);
        Traversal(root->right);
        totalsum = (totalsum + root->val)%m;
    }
    int  Traversal1(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        currsum = root->val%m + (Traversal1(root->right))%m + (Traversal1(root->left))%m;// Most Important Step to find sum of a sub tree

        maxi = max(maxi,( currsum )*(totalsum - currsum));//To store the the maximum product of sum of subtrees

        return currsum;
    }
    int maxProduct(TreeNode* root) {
        Traversal(root);// To calculate total sum of all nodes
        Traversal1(root);// To calculate sum of subtrees and store maximum of product of subtrees 
        return maxi%m;
    } 
};