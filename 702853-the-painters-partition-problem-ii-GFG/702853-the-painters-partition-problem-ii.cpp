class Solution {
  public:
    bool canpaint(vector<int>& arr, int k,int n,long long limit){
        int count = 1;
        long long time = 0;
        
        for(int i=0;i<n;i++){
            if(time + arr[i] <= limit){
                time += arr[i];
            }else{
                count++;
                time = arr[i];
                if(count > k){
                    return false;
                }
            }
        }
        return true;
        
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int res = -1;
        if(n < k){
            return -1;
        }
        long long  low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        
        while(low <= high){
            long long guess = low + (high-low)/2;
            if(canpaint(arr,k,n,guess)){
                res = guess;
                high = guess-1;
            }else{
                low = guess+1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna