class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int ans = nums[0];
        int best_ending = nums[0];

        for(i=1;i<nums.size();i++){
            int v1 = best_ending + nums[i];
            int v2 = nums[i];

            best_ending = max(v1,v2);
            ans = max(ans,best_ending);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna