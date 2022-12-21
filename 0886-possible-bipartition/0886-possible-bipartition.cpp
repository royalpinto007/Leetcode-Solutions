class Solution {
public:
    bool bfs(int source, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.push(source);
        color[source] = 0;  // Start with marking source as `RED`.

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighbor : adj[node]) {
                // If there is a conflict, return false.
                if (color[neighbor] == color[node]) return false;
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        vector<int> color(n + 1, -1); // 0 stands for red and 1 stands for blue.
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                // For each pending component, run BFS.
                if (!bfs(i, adj, color))
                    // Return false, if there is conflict in the component.
                    return false;
            }
        }
        return true;
    }
};