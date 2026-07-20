class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        int res = -1;
        while(low<= high){
            int mid = (low+high)/2;
            
            if(arr[mid] < x){
                low = mid+1;
            }else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna