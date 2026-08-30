class Solution {
public:
    bool cycle = false;

    void dfs(vector<vector<int>>& a, int node, int parent,
             vector<bool>& vis) {

        vis[node] = 1;

        for(int j = 0; j < a[node].size(); j++) {

            int neigh = a[node][j];

            if(vis[neigh] == 1 && neigh != parent) {
                cycle = true;
                return;
            }

            if(vis[neigh] == 0) {
                dfs(a, neigh, node, vis);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> a(n + 1);

        for(int i = 0; i < edges.size(); i++) {

            int src = edges[i][0];
            int dest = edges[i][1];

            // Add current edge
            a[src].push_back(dest);
            a[dest].push_back(src);

            vector<bool> vis(n + 1, 0);

            cycle = false;

            // Check cycle after adding this edge
            for(int j = 1; j <= n; j++) {

                if(vis[j] == 0) {
                    dfs(a, j, -1, vis);
                }

                if(cycle)
                    break;
            }

            // Current edge creates cycle
            if(cycle) {
                return {src, dest};
            }
        }

        return {};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna