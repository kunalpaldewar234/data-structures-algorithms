class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int i=0;
        int result = arr[0];
        int nocoding = arr[0];
        int onecoding = arr[0];

        for(i=1;i<arr.size();i++){
            int prevnocoding = nocoding;
           
            
            nocoding = max((prevnocoding+arr[i]),arr[i]);
            onecoding = max(onecoding+arr[i],prevnocoding);

            result = max(result,max(nocoding,onecoding));
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna