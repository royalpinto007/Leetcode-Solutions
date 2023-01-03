class Solution {
    vector<int>g[100005];
    int level_bob[100005];
    bool vis[100005];
    
    int pa[100005];
    
    long long max_amount=-1e9;
    vector<int>Amount;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        Amount = amount;
        for(auto v: edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        
        for(int i=0; i<edges.size()+1; i++) level_bob[i]=1e9;
        memset(vis, false , sizeof(vis));
        level_bob[bob]=0;
        dfs_bob(bob, -1);
        
       
        /// Path from 0 to bob's node and mark these node using map
        map<int, bool>mpp;
        int node=0;
        while(pa[node]!=-1){
            mpp[node]=true;
            node =pa[node];
        }
        mpp[bob]=true;
        
        for(int i=0; i<edges.size()+1; i++)
        {
            if(!mpp[i]){ /// if this node isn't in the bob's path then set level to MAX_INT
                level_bob[i]=1e9;
            }
        }
        
       
        
        memset(vis, false, sizeof(vis)); /// clear vis array
        int level=0;
        long long sum_amount=0;
        dfs_alice(0, level, sum_amount);
        
        return (int)max_amount;
    }
    
    void dfs_bob(int u, int p)
    {
        vis[u]=true;
        pa[u]=p;  /// parent set
        for(auto v: g[u]){
            if(!vis[v]){
                level_bob[v]=level_bob[u]+1; /// level update
                dfs_bob(v, u);
            }
        }
    }
    
    void dfs_alice(int u, int level, long long sum_amount)
    {
        vis[u]=true;
        if(level<level_bob[u]) sum_amount+=Amount[u]; /// if alice's current level is lower then it means that bob didn't reach this node before alice thats why add the Amount
        else if(level==level_bob[u]) sum_amount+=(Amount[u]/2); /// if alice's current level is equal to bob that means they are in that node at the same time thats why they will share amount so half goes to alice
     
        if( u!=0 && g[u].size()==1){ /// if this node is leaf node not the 0 node
            max_amount=max(max_amount, sum_amount); /// max_amount update
        }
        for(auto v: g[u]){
            if(!vis[v]){
                dfs_alice(v, level+1, sum_amount);
            }
        }
    }
    
};