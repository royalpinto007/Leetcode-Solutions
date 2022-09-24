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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector <int> path;
        DFS(path, root, sum, res);
        return res;
    }
    
    void DFS(vector <int> path, TreeNode* root, int sum, vector<vector<int>> &res)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == sum)
            {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
        }
        path.push_back(root->val);
        DFS(path, root->left, sum - root->val, res);
        DFS(path, root->right, sum - root->val, res);
        path.pop_back();
    }
};


// using backtracking

// class Solution {
// public:
//     vector<vector<int>> ans;
//     int sum;
    
//     void backtrack(TreeNode* cur, vector<int>& path){
//         //cur must not be nullptr
//         //when entering this function, cur is added in "path"
//         if(!cur->left && !cur->right){
//             // for(const int& e : path) cout << e << " ";
//             // cout << endl;
//             if(accumulate(path.begin(), path.end(), 0) == sum){
//                 ans.push_back(path);
//             }
//         }else{
//             if(cur->left){
//                 path.push_back(cur->left->val);
//                 backtrack(cur->left, path);
//                 path.pop_back();
//             }
            
//             if(cur->right){
//                 path.push_back(cur->right->val);
//                 backtrack(cur->right, path);
//                 path.pop_back();
//             }
//         }
//     }
    
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         if(!root) return vector<vector<int>>();
        
//         this->sum = sum;
        
//         vector<int> path = {root->val};
//         backtrack(root, path);
        
//         return ans;
//     }
// }