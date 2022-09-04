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
    //(x, y) -> values
    map<int, map<int, multiset<int>>> coord2values;
    
    void dfs(TreeNode* node, int x, int y){
        if(node == nullptr) return;
        
        coord2values[x][y].insert(node->val);
        
        dfs(node->left, x-1, y+1);
        dfs(node->right, x+1, y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        
        vector<vector<int>> ans;
        
        for(auto itx = coord2values.begin(); itx != coord2values.end(); ++itx){
            vector<int> line;
            for(auto ity = itx->second.begin(); ity != itx->second.end(); ++ity){
                // cout << "(" << itx->first << ", " << ity->first << "): ";
                // for(auto itn = ity->second.begin(); itn != ity->second.end(); ++itn){
                //     cout << *itn << " ";
                // }
                // cout << endl;
                line.insert(line.end(), ity->second.begin(), ity->second.end());
            }
            ans.push_back(line);
        }
        
        return ans;
    }
};

/*
class Solution {
public:
    
    void traverse(map<int, map<int, vector<int>>>& mp, int level, int dist, TreeNode* root)
    {
        mp[dist][level].push_back(root->val);
        
        if(root->left)
        {
            traverse(mp, level+1, dist-1, root->left);
        }
        if(root->right)
        {
            traverse(mp, level+1, dist+1, root->right);
        }
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        map<int, map<int, vector<int>>>::iterator mit;
        map<int, vector<int>>::iterator it;
        vector<vector<int>> res;
        
        traverse(mp, 0, 0, root);
      
        for (mit = mp.begin(); mit != mp.end(); mit++)
        {
            vector<int> tmp;
            for(it = (mit->second).begin(); it != (mit->second).end(); it++)
            {
                sort((it->second).begin(), (it->second).end());
                for (auto i: it->second)
                {
                    tmp.push_back(i);
                }
            }
            res.push_back(tmp);
        }
        
        return res;
        
    }
};
*/