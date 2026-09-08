class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        vector<bool>vis(n,0);
        queue<int>q;
        for(int i =0;i<prerequisites.size();i++){
            int src = prerequisites[i][0];
            int dest = prerequisites[i][1];

            adj[src].push_back(dest);
            indeg[dest]++;
        }
        for(int i =0;i<indeg.size();i++){
            if(indeg[i] == 0){
                q.push(i);
                vis[i] = 1;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j =0;j<adj[node].size();j++){
                int neigh = adj[node][j];
                indeg[neigh]--;
                if(indeg[neigh] == 0){
                    q.push(neigh);
                     vis[neigh] = 1;
                }
            }
        }
        for(int i =0;i<n;i++){
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