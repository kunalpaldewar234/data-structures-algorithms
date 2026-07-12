class Solution {
  public:
    bool isIntersect(vector<vector<int>> arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        
        int start1 = arr[0][0];
        int end1 = arr[0][1];
        
        for(int i=1;i<arr.size();i++){
            int start2 = arr[i][0];
            int end2 = arr[i][1];
            
            if(end1 >= start2){
                return true;
            }
            end1 = arr[i][1];
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna