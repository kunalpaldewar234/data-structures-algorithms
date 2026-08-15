class Solution {
  public:
    void dfs(vector<vector<int>>&adj,int node,vector<int>&res,vector<bool>&vis){
        res.push_back(node);
        vis[node]=1;
        
        for(int i=0;i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(vis[neigh] == 0){
                dfs(adj,neigh,res,vis);
            
            }
        }
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>res;
        vector<bool>vis(n,0);
        dfs(adj,0,res,vis);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna