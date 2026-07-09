class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans(nums.size());
        int left = 0;
        int right =0;
        int sum =0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        ans[0] = sum-nums[0];
        
        for(int i=1;i<nums.size();i++){
            left += nums[i-1];
            right = sum-nums[i]-left;

            ans[i] = abs(left-right);
        }

        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna