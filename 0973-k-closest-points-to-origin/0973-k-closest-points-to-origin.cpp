class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first < b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

        for(int i =0;i<n;i++){
            int dist = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);

            pair<int,int>curr = {dist,i};
            if(pq.size() < k){
                pq.push(curr);
                continue;
            }
            if(curr.first > pq.top().first){
                continue;
            }
            pq.push(curr);
            pq.pop();
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna