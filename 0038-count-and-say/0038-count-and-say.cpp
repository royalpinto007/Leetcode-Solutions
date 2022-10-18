class Solution {
public:
    string countAndSay(int n) {
        // base case
        if(n==1){
            return "1";
        }
        
        // recursive case
        string prev=countAndSay(n-1);
        cout<<n<<" "<<prev<<"\n";
        
        string ans;
        int len=prev.length();

        for(int i=0;i<len;){
            int j=i;
            int count=0;
            while(prev[j]==prev[i]&&j<len){
                j++;
                count++;
            }
            char c='0'+count;
            ans+=c;
            ans+=prev[i];
            i=j;
        }
        
        return ans;
    }
};