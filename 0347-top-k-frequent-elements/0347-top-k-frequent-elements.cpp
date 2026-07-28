class Solution {
public:
    struct cmp{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
        return a.first > b.first;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
    int n = nums.size();
    unordered_map<int,int>f;
    for(int i=0;i<n;i++){
        f[nums[i]]++;
    }
    for(auto i : f){
        int element = i.first;
        int freq = i.second;

        pair<int,int>curr = {freq,element};
        if(pq.size() < k){
            pq.push(curr);
            continue;
        }
        if(curr.first < pq.top().first){
            continue;
        }
        pq.pop();
        pq.push(curr);
    }
    vector<int>res;
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna