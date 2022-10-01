class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')
        return 0;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) {
                if(s[i] != '0') {
                    dp[i] = dp[i-1] + (i-2>=0?dp[i-2]:1);
                } else {
                    dp[i] = (i-2>=0?dp[i-2]:1);
                }
            } else if(s[i] == '0') {
                return 0;
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp.back();
    }
};