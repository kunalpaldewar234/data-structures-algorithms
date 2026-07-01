class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int res = 0;
        int low = 0;
        int high = k-1;
        int sum =0;
        for(int i=0;i<k;i++){
            sum = sum+arr[i];
        }
        
        while(high<arr.size()){
            res = max(sum,res);
            low++;
            high++;
            if(high == arr.size()){
                break;
            }
            sum = sum-arr[low-1];
            sum = sum +arr[high];
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna