class Solution {
  public:
  bool issort(vector<int>&arr,int i,int n){
        if(i == n || i== n-1){
            return true;
        }
        if(arr[i] > arr[i+1]){
            return false;
        }
        
        return issort(arr,i+1,n);
  }
    bool isSorted(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i =0;
        return issort(arr,i,n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna