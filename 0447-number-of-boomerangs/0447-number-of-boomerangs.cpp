class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        map<vector<int>, vector<int>>m;
        int cnt=0;
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                if(i!=j){
                    int dis=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                    m[points[i]].push_back(dis);
                }
            }
        }
        for(auto it: m){
            map<int, int>m1;
            for(auto it1: it.second){m1[it1]++;}
            for(auto it1: m1){
                cnt+=it1.second*(it1.second-1);
            }
        }
        return cnt;
    }
};