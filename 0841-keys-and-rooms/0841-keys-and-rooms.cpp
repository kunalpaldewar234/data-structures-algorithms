class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i =0;i<adj[node].size();i++){
                int neigh = adj[node][i];
                if(vis[neigh] == 0 ){
                    vis[neigh] = 1;
                    q.push(neigh);    
                }
            }
        }
        for(int i=0;i<n;i++){
        if(vis[i] == 0){
            return false;
        }
    }
    return true;
    }
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna