class Solution {
  public:
    int shortestPath(int n, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>>adj(n);
        vector<int>res(n,-1);
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        for(int i=0;i<edges.size();i++){
            int s= edges[i][0];
            int d = edges[i][1];
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        q.push({src,0});
        vis[src] = 1;
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            int node = p.first;
            int dist = p.second;
            res[node] = dist;
            for(int j=0;j<adj[node].size();j++){
                int neigh = adj[node][j];
                if(vis[neigh] == 0){
                    q.push({neigh,dist+1});
                    vis[neigh] = 1;
                }
            }
        }
        return res[dest];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna