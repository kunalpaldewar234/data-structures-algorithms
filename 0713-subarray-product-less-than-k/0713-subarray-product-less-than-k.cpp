class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
         int count = 0;
        int prod = 1;
        int low =0;
        int high =0;

        while(high < arr.size()){
            prod = prod * arr[high];

            while(prod >= k){
                prod = prod/arr[low];
                low++;
            }
            count = count+(high-low+1);
            high++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna