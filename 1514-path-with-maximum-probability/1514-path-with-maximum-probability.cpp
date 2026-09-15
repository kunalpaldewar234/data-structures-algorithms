class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double,int>>>a(n);
        vector<double>prob(n,0.0);
        priority_queue<pair<double, int>> pq;
        for(int i=0;i<edges.size();i++){
            int s = edges[i][0];
            int d = edges[i][1];
            double p = succProb[i];

            a[s].push_back({p,d});
            a[d].push_back({p,s});
        }
        prob[start_node] = 1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            pair<double,int>p = pq.top();
            pq.pop();
            double current_prob = p.first;
            int node = p.second;
            if(current_prob < prob[node]){
                continue;
            }
            for(int j=0;j<a[node].size();j++){
                double p = a[node][j].first;
                int neigh = a[node][j].second;
                if(prob[neigh] < current_prob*p){
                    prob[neigh] = current_prob*p;
                    pq.push({current_prob*p,neigh});
                }
            }
        }
    return prob[end_node];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna