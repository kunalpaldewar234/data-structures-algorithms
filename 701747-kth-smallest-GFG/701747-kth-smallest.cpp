class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        int i;
        int n = arr.size();
        for(i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        for(i=k;i<n;i++){
            if(arr[i] >= pq.top()){
                continue;
            }
            pq.pop();
            pq.push(arr[i]);
        }
        return pq.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna