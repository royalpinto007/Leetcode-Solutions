#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            // we'll not repeat ith
            if(i==0||nums[i]>nums[i-1]){

                // two pointers
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int val=nums[i]+nums[j]+nums[k];
                    
                    if(val==target){
                        return val;
                    }
                    
                    if(abs(val-target)<abs(closest)){
                        closest=target-val;
                    }
                    
                    if(val<target){
                        int j_val=nums[j];
                        while(j<k&&nums[j]==j_val){
                            j++;
                        }
                    }else{
                        int k_val=nums[k];
                        while(j<k&&nums[k]==k_val){
                            k--;
                        }
                    }
                
                }
            }

        }

        return target-closest;
    }
};