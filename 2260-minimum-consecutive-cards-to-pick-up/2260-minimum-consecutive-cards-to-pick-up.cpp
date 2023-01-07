class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, vector<int>>m;
        int ans=1e9;
        for(int i=0; i<cards.size(); i++){
            m[cards[i]].push_back(i);
        }
        for(auto it: m){
            //cout<<it.first<<" "<<it.second.size()<<endl;
            // for(auto it1: it.second){
            //     cout<<it1<<" ";
            // }
            //cout<<"h"<<endl;
            if(it.second.size()>1){
                int cnt=1e9;
                for(int j=0; j<it.second.size()-1; j++){
                    cnt=min(cnt, it.second[j+1]-it.second[j]+1);
                }
                ans=min(ans, cnt);
                //cout<<ans<<" "<<cnt<<endl;
            }
        }
        if(ans==1e9){return -1;}
        return ans;
    }
};