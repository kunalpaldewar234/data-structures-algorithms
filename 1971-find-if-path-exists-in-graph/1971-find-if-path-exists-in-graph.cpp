class Solution {
public:
void dfs(vector<vector<int>>&adj,int node,vector<bool>&vis){
    vis[node] = 1;
    for(int i =0;i<adj[node].size();i++){
        int neigh = adj[node][i];
        if(vis[neigh] == 0){
            dfs(adj,neigh,vis);
        }
      
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,0);
        dfs(adj,source,vis);
        return vis[destination];

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna