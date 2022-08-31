class Solution 
{
public:
     int removeDuplicates(vector<int>& nums)
     {
        int j=0;
        for(int i=1;i<nums.size();i++)
	{
            if(nums[j]!=nums[i]) 
                j++;
                nums[j]=nums[i];  
        }
        return j+1;
    }
};

/*
int count = 0;
for(int i = 1; i < n; i++)
	{
    		if(A[i] == A[i-1]) count++;
    		else A[i-count] = A[i];
	}
return n-count;
*/
