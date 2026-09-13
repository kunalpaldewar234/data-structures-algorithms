class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int, int>>> adj(n);

        // Build graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});   // remove this if graph is directed
        }

        // {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entry
            if (d > dist[node]) {
                continue;
            }

            // Traverse neighbours
            for (auto it : adj[node]) {

                int neigh = it.first;
                int wt = it.second;

                if (d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna