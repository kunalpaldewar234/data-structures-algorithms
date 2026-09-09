class Solution {
public:
bool res = true;
void dfs(vector<vector<int>>&adj,int node,int c,vector<int>&colors){
    colors[node] = c;
    for(int j =0;j<adj[node].size();j++){
        int neigh = adj[node][j];
        if(colors[neigh] == c){
            res = false;
        }
        if(colors[neigh] == -1){
            dfs(adj,neigh,1-c,colors);
        }
    }
    return;
}
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>colors(n,-1);
        for(int i =0;i<colors.size();i++){
            if(colors[i] == -1){
                dfs(adj,i,0,colors);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna