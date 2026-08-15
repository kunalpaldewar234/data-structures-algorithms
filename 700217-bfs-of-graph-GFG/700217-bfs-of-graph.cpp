class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>res;
        vector<bool>vis(n,0);
        queue<int>q;
        
        q.push(0);
        vis[0] = 1;
       
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            
            for(int i=0;i<adj[node].size();i++){
                int neigh = adj[node][i];
                if(vis[neigh] == 0){
                    q.push(neigh);
                    vis[neigh] = 1;
                }
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna