class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int xx = INT_MAX, yy = INT_MAX; 
        for (auto& p : trees) 
            if (p[1] < yy || (p[0] < xx && p[1] == yy)) {
                xx = p[0]; 
                yy = p[1]; 
            }
        
        map<double, vector<vector<int>>> mp; 
        for (auto& p : trees) mp[atan2(p[1] - yy, p[0] - xx)].push_back(p); 
        
        vector<vector<int>> vals; 
        for (auto& [k, v] : mp) {
            sort(v.begin(), v.end(), [&](auto& lhs, auto& rhs) {
                return abs(lhs[0] - xx) + abs(lhs[1] - yy) < abs(rhs[0] - xx) + abs(rhs[1] - yy); 
            }); 
            if (k == mp.rbegin()->first && vals.size()) reverse(v.begin(), v.end()); 
            for (auto& x : v) vals.push_back(x); 
        }
        
        vector<vector<int>> ans; 
        for (auto& p : vals) {
            while (ans.size() >= 2) {
                auto p0 = ans.back(); ans.pop_back(); 
                auto p1 = ans.back(); 
                if ((p0[0] - p1[0]) * (p[1] - p0[1]) - (p[0] - p0[0]) * (p0[1] - p1[1]) >= 0) {
                    ans.push_back(p0); 
                    break; 
                }
            }
            ans.push_back(p); 
        }
        return ans; 
    }
};