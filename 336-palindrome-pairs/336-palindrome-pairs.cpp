class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> ans;
        unordered_map<string,int> m;
        set<int> s; 
        int len = words.size();
        for(int i = 0; i < len; ++i) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        
        for(int i = 0; i < len; ++i) {
            string tmp = words[i];
            int tmp_len = tmp.size();
            reverse(tmp.begin(),tmp.end());
            
            
            if(m.count(tmp) && m[tmp] != i) {
                ans.push_back({m[tmp] , i});  
            }
            
            auto a = s.find(tmp_len);  
            for(auto it = s.begin(); it != a; ++it) {
                int cur_len = *it;
                
                if(isPalindrome(tmp, 0, tmp_len-cur_len-1) && m.count(tmp.substr(tmp_len-cur_len))) {
                    ans.push_back({i , m[tmp.substr(tmp_len-cur_len)]});
                }
                
                if(isPalindrome(tmp, cur_len, tmp_len-1) && m.count(tmp.substr(0, cur_len))) {
                    ans.push_back({m[tmp.substr(0, cur_len)], i});
                }
            }
            
        }
        
        return ans;
    }
    
    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }
        
        return true;
    }
};