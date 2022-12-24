class Solution {
public:
    int numTilings(int n) 
    {
        vector<long long>dp(n + 1);
        dp[1] = 1; dp[0] = 1;
        int MOD = 1000000007;
        for (int width = 2; width <= n; width++)
        {
            long long totalWays = 0;
            for (int fixWidth = 1; fixWidth <= width; fixWidth++)
            {
                int leftWidth = width - fixWidth;
                long long ways = dp[leftWidth]; 
                if (fixWidth > 2) ways = (ways * 2) % MOD; //because from fixWidth > 2, two configurations exist for each case
                //fixWidthConfiguration appended to all dp[leftWidth] configurations
                
                totalWays = (totalWays + ways) % MOD;
            }
            dp[width] = totalWays;
        }
        return dp[n];
    }
};