class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res = -1;

        while(low<= high){
            int guess = (low+high)/2;

            if(nums[guess] > nums[n-1]){
                // part 2 ka element hai!
                low = guess+1;
            }else{
                res = nums[guess];
                high = guess-1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna