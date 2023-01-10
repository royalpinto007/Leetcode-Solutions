class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int M=1e9+7, cnt=0;
        map<int, int>m;
        vector<int>v;
        for(int i=0; i<nums.size(); i++){
            int x=nums[i], val=0;
            while(x){
                val+=x%10;
                if(x/10){val*=10;}
                x/=10;
            }
            v.push_back(val);
        }
        //for(int i=0; i<nums.size(); i++){cout<<v[i]<<" ";}cout<<endl;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i]-v[i])!=m.end()){
                cnt+=(m[nums[i]-v[i]])%M;
                cnt%=M;
            }
            m[nums[i]-v[i]]++;
        }
        return cnt%M;
    }
};