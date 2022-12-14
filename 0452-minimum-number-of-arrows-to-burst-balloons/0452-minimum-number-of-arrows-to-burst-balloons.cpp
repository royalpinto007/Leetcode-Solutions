// https://www.youtube.com/watch?v=fvBhjAp0j9c&ab_channel=AyushiSharma
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        
        sort(p.begin(), p.end());
        
        // to sort it according to the lastpoint 
        int lastpoint = p[0][1];
        int ans = 1;
        
        for(auto point : p) {
            if(point[0] > lastpoint) {
                ans++;
                lastpoint = point[1];
            }
            lastpoint = min(point[1],lastpoint);
        }
        return ans;
    }
};