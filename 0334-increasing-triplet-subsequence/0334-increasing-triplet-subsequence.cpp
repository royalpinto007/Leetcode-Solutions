#include <climits>
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x1 = INT_MAX, x2 = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < x1)
                x1 = nums[i];
            else if (nums[i] > x1 && nums[i] < x2)
                x2 = nums[i];
            else if (nums[i] > x2)
                return true;
        }
        return false;
    }
};