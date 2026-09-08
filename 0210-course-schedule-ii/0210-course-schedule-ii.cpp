class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        queue<int>q;
        for(int i=0;i<edges.size();i++){
            int src = edges[i][1];
            int dest = edges[i][0];
            
            adj[src].push_back(dest);
            indeg[dest]++;
        }
        for(int i =0;i<indeg.size();i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int j =0;j<adj[node].size();j++){
                int neigh = adj[node][j];
                indeg[neigh]--;
                if(indeg[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
       if(res.size() != n){
        return {};
       }else{
        return res;
       }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna