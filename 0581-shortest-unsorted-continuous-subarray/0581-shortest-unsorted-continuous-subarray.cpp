class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //create a duplicate of original array and sort it.
        vector<int> temp;
        temp = nums;
        sort(temp.begin(),temp.end());
        int n = nums.size();
        int i=0,j=n-1;
        //while going from left to right find maximum index of the array upto which the elements is correctly positioned/already sorted
        for(;i<n;i++)
        {
            if(nums[i]!=temp[i])
                break;
        }
        //while going from right to left find maximum index of the array upto which the elements is correctly positioned/already sorted
        for(;j>=0;j--)
        {
            if(nums[j]!=temp[j])
                break;
        }
        int c=0;
        //find the total number of elements that are not sorted and needs to be sorted, these elements lie between the two already sorted subarrays, i.e. the left to right already sorted subarray and right to left already sorted subarray.
        for(int k=i;k<=j;k++)
            c++;
        return c;
    }
};