class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high =n-1;

        while(low <= high){
            int guess = (low+high)/2;

            if(nums[guess] == target){
                return guess;
            }else if(nums[guess] < target){
                low = guess +1;
            }else{
                high = guess-1;
            }

        }
        return low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna