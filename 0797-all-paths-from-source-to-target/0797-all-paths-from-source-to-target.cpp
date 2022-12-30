class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& v, int start) {
        for (int i = 0; i < graph[start].size(); i++) {
            v.push_back(graph[start][i]);
            if (graph[start][i] == graph.size() - 1) ans.push_back(v);
            dfs(graph, ans, v, graph[start][i]);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v; v.push_back(0);
        vector<vector<int>> ans;
        dfs(graph, ans, v, 0);
        return ans;
    }
};