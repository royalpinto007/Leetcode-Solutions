
#define LL long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        LL ans = 0;
        vector<map<LL, int>> cnt(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                LL delta = (LL)A[i] - (LL)A[j];
                int sum = 0;
                if (cnt[j].find(delta) != cnt[j].end()) {
                    sum = cnt[j][delta];
                }
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        }

        return (int)ans;
    }
};

// #define LL long long
// class Solution {
// public:
//     int n;
//     int ans;
//     void dfs(int dep, vector<int>& A, vector<LL> cur) {
//         if (dep == n) {
//             if (cur.size() < 3) {
//                 return;
//             }
//             for (int i = 1; i < cur.size(); i++) {
//                 if (cur[i] - cur[i - 1] != cur[1] - cur[0]) {
//                     return;
//                 }
//             }
//             ans ++;
//             return;
//         }
//         dfs(dep + 1, A, cur);
//         cur.push_back(A[dep]);
//         dfs(dep + 1, A, cur);
//     }
//     int numberOfArithmeticSlices(vector<int>& A) {
//         n = A.size();
//         ans = 0;
//         vector<LL> cur;
//         dfs(0, A, cur);
//         return (int)ans;
//     }
// };
