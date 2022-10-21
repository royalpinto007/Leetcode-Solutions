class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i+1 < nums.size(); i++){
            // cout << "[" << i+1 << ", " << i+k << "]" << endl;
            int finish = min((int)nums.size(), i+k+1);
            if(find(nums.begin()+i+1, nums.begin()+finish, nums[i])
              != nums.begin()+finish){
                // cout << endl;
                return true;
            }
        }
        // cout << endl;
        return false;
    }
};

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         for(int i = 0; i < nums.size(); i++){
//             for(int j=i+1; (j <=i+k) && (j < nums.size()); j++){
//                 // cout << "i: " << i << "j: " << j << endl;
//                 if(nums[i] == nums[j]) return true;
//             }
//         }
//         // cout << endl;
//         return false;
//     }
// };