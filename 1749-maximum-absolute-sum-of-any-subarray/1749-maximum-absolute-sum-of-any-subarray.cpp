class Solution {
public:
    int maxsum(vector<int>nums){
        int best_ending = nums[0];
        int ans = nums[0];
        int i=0;

        for(i=1;i<nums.size();i++){
            int v1 = best_ending+nums[i];
            int v2 = nums[i];

            best_ending = max(v1,v2);
            ans = max(ans,best_ending);
        }
        return ans;
    }
     int minsum(vector<int>nums){
        int best_ending = nums[0];
        int ans = nums[0];
        int i=0;

        for(i=1;i<nums.size();i++){
            int v1 = best_ending+nums[i];
            int v2 = nums[i];

            best_ending = min(v1,v2);
            ans = min(ans,best_ending);
        }
        return ans;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        return max(maxsum(nums),abs(minsum(nums)));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna