class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right =0;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if (sum - nums[0] == 0){
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            left += nums[i-1];
            right = sum-nums[i]-left;

            if(left == right){
                return i;
            }
        }

        
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna