// https://www.code-recipe.com/post/two-sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
        int low=0;
        int high=nums.size()-1;
        vector<pair<int,int>> v;
        pair<int,int> p;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        
        sort(v.begin(),v.end());
        
        while(low<high)
        {
            if(v[low].first+v[high].first==target)
            {
                p.first=v[low].second;
                p.second=v[high].second;
                low++;
                high--;
            }
            
            else if(v[low].first+v[high].first<target)
                low++;
            else high--;
        }
        vector<int> vv;
        vv.push_back(p.first);
        vv.push_back(p.second);
        return vv;
       
    }
};

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int t = nums.size();
        for (int i=0; i< t; i++)
        {
            for (int j=0; j<t; j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    if(i!=j)
                    {
                         return {i, j};
                    }
                }
            }
        }
        return {-1,-1};
    }
};
*/
