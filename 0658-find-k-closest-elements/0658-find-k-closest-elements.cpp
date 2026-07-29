class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first<b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
       int n = arr.size();

       for(int i=0;i<n;i++){
        int dist = abs(arr[i]-x);
        pair<int,int>curr = {dist,arr[i]};
        if(pq.size() < k){
            pq.push(curr);
            continue;
        }
        if(curr.first > pq.top().first || curr.first == pq.top().first && curr.second > pq.top().second){
            continue;
        }
        pq.push(curr);
        pq.pop();
       }
        vector<int>res;
       while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
       }
       sort(res.begin(),res.end());
       return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna