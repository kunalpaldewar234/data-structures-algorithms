class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();

        vector<vector<pair<int,int>>> adj(n);

        // dp[node][time] = minimum cost
        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX));

        for(int i = 0; i < edges.size(); i++) {

            int src = edges[i][0];
            int dest = edges[i][1];
            int wt = edges[i][2];

            adj[src].push_back({wt, dest});
            adj[dest].push_back({wt, src});
        }

        // {cost, {time, node}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dp[0][0] = passingFees[0];

        pq.push({passingFees[0], {0, 0}});

        while(!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int currCost = p.first;
            int currTime = p.second.first;
            int node = p.second.second;

            if(currCost > dp[node][currTime]) {
                continue;
            }

            if(node == n - 1) {
                return currCost;
            }

            for(int j = 0; j < adj[node].size(); j++) {

                int nodeTime = adj[node][j].first;
                int neigh = adj[node][j].second;

                int newTime = currTime + nodeTime;

                if(newTime > maxTime) {
                    continue;
                }

                int newCost = currCost + passingFees[neigh];

                if(newCost < dp[neigh][newTime]) {

                    dp[neigh][newTime] = newCost;

                    pq.push({
                        newCost,
                        {newTime, neigh}
                    });
                }
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna