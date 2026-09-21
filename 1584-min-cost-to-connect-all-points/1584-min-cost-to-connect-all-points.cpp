class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n  = points.size();
        int sum = 0;
        vector<vector<pair<int,int>>>a(n);
        for(int i=0;i<points.size();i++){
             for(int j=i+1;j<points.size();j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int wt = abs(x1-x2)+abs(y1-y2);
                a[i].push_back({j, wt});
                a[j].push_back({i, wt});
            }
        }
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            int w = p.first;
            int node = p.second;
            if(vis[node] == 1){
                continue;
            }
            sum += w;
            vis[node] = 1;
            for(int j=0;j<a[node].size();j++){
                int neigh = a[node][j].first;
                int neighwt = a[node][j].second;
                if(vis[neigh] == 0){
                    pq.push({neighwt,neigh});
                }
            }
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna