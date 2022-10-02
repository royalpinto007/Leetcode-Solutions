class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        static const int MOD = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= d; ++i) {
            dp[i % 2] = vector<int>(target + 1);
            for (int k = 1; k <= f; ++k) {
                for (int j = k; j <= target; ++j) {
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j - k]) % MOD;
                }
            }
        }
        return dp[d % 2][target] % MOD;
    }
};

/*
class Solution {
public:
    const int MOD = 1e9+7;
    int numRollsToTarget(int d, int f, int target) 
    {
        vector<vector<int>> dp(d+1,vector<int>(target+1,0));
        dp[0][0] = 1; // Because with dice 1 and we can make sum 1 in 1 way
        for(int dice=1;dice<=d;dice++)
        {
            for(int t=1;t<=target;t++)
            {
                for(int face=1;face<=f;face++)
                {
                    if(t>=face)
                        dp[dice][t] = (dp[dice][t]%MOD + dp[dice-1][t-face]%MOD)%MOD;
                }
            }
        }
        return dp[d][target];
    }
};
*/