class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
       
        sort(nums.begin(), nums.end());
        
        // For each query, collect numbers from lowest to highest.
        // If their sum exceeds the limit 'query', move on to the next query.
        vector<int> ans;
        for (auto query : queries) {
            int count = 0;
            for (auto num : nums) {
                if (query >= num) {
                    query -= num;
                    count++;
                }
                else {
                    break;
                }
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};


/*
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // Get the prefix sum array of the sorted 'nums'.
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        
        // For each query, find its insertion index to the prefix sum array.
        vector<int> answer;
        for (auto query : queries) {
            int index = upper_bound(nums.begin(), nums.end(), query) - nums.begin();
            answer.push_back(index);
        }
        
        return answer;
    }
};
*/