class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int>dp(B.size()+1,0); 
        int res = 0;
        for(int i = 0; i<A.size(); i++)
            for(int j = B.size()-1; j>=0; j--)
                res = max(res, dp[j+1] = A[i] == B[j] ? dp[j]+1: 0);
                
        return res;
    }
};

// class Solution {
// public:
//     int findLength(vector<int>& A, vector<int>& B) {
//         vector<vector<int>>dp(A.size()+1, vector<int>(B.size()+1,0));
//         int res = 0;
//         for(int i = 0; i<A.size(); i++)
//             for(int j = 0; j<B.size(); j++)
//                 if(A[i] == B[j]){
//                     dp[i+1][j+1] = dp[i][j]+1; //dp[i+1][j+1] 
//                     res = max(res,dp[i+1][j+1]);
//                 }
//         return res;
//     }
// };


// class Solution {
// public:
//     int findLength(vector<int>& A, vector<int>& B) {
//         vector<vector<int>>dp(A.size()+1, vector<int>(B.size()+1,0));
//         int res = 0;
//         for(int i = A.size()-1; i>=0; i--)
//             for(int j = B.size() - 1; j>=0; j--)
//                 if(A[i] == B[j]){
//                     dp[i][j] = dp[i+1][j+1]+1;
//                     res = max(res,dp[i][j]);
//                 }
//         return res;
//     }
// };
