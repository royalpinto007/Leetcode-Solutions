class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<int> dp(size(multipliers) + 1);
        for (int i = size(multipliers) - 1, l = size(nums) - size(multipliers); i >= 0 ; --i, ++l) {
            vector<int> new_dp(size(dp) - 1);
            for (int j = 0; j < size(new_dp); ++j) {
                new_dp[j] = max(multipliers[i] * nums[j]+ dp[j + 1],
                                multipliers[i] * nums[j + l] + dp[j]);
            }
            dp = move(new_dp);
        }
        return dp[0];
    }
};

// class Solution {
// public:
//     int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//         int n = nums.size();
//         int m = multipliers.size();
//         vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        
//         int score = INT_MIN;
//         for (int k = 1; k <= m; k++) {
//             for (int l = 0; l <= k; l++) {
//                 int pick_left = (l == 0 ? INT_MIN : dp[l-1][k-l] + multipliers[k-1] * nums[l-1]);
//                 int pick_right = (l == k ? INT_MIN : dp[l][k-l-1] + multipliers[k-1] * nums[n-k+l]);
//                 dp[l][k-l] = max(pick_left, pick_right);

//                 if (k == m) {
//                     score = max(score, dp[l][k-l]);
//                 }
//             }
//         }
        
//         return score;
//     }
// };