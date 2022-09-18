class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if(N == 0) return 0;
        int ans = 0;
        
        vector<int> leftMax(N), rightMax(N);
        leftMax[0] = height[0];
        for(int i = 1; i < N; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        rightMax[N-1] = height[N-1];
        for(int i = N-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        for(int i = 1; i < N-1; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int left = 0, right = 0;
//         int ans = 0;
//         int N = height.size();
        
//         while(right < N){
//             int valley = height[left];
            
//             //left wall should have height > 0
//             while(left < N && height[left] == 0){
//                 left++;
//             }
//             //cannot find left wall
//             if(left == N) break;

//             //right wall should be larger than valley
//             for(right = left+1; right < N && height[right] <= valley; right++){
//                 valley = min(valley, height[right]);
//             }
//             //cannot find right wall
//             if(right == N) break;
//             // cout << "left: " << left << ", right: " << right << endl;
            
//             //we've found a valid right wall,
//             //now we want to discover higher right wall
//             //we only need to find a higher right wall when right wall is lower than left wall
//             int head = right+1;
//             if(height[left] > height[right]){
//                 int last = right;
//                 while(head < N && height[head] < height[left]){
//                     if(height[head] > height[last]){
//                         last = head;
//                     }
//                     head++;
//                 }
//                 if(head < N && height[head] >= height[left]){
//                     //found a right wall >= left wall
//                     right = head;
//                 }else{
//                     //found the highest right wall > original right wall
//                     right = last;
//                 }
//             }
            
//             //calculate current trapping water amount
//             int lh = height[left], rh = height[right];
//             for(int i = left+1; i < min(right, N); i++){
//                 // cout << i << ", height: " << height[i] << endl;
//                 //we should take max(0, x) here!
//                 ans += max(0, min(lh, rh) - height[i]);
//             }
//             // cout << left << " " << right << " " << valley << " " << ans << endl;

//             left = right;
//         }
        
//         return ans;
//     }
// };