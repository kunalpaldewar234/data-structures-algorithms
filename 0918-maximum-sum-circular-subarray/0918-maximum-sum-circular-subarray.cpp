class Solution {
public:
    int maxsum(vector<int>nums){
        int i=0;
        int bestending = nums[0];
        int result = nums[0];

        for(i =1;i<nums.size();i++){
            bestending = max((bestending+nums[i]),nums[i]);
            result = max(result,bestending);
        }
        return result;
    }
    int minsum(vector<int>nums){
        int i=0;
        int bestending = nums[0];
        int result = nums[0];

        for(i =1;i<nums.size();i++){
            bestending = min((bestending+nums[i]),nums[i]);
            result = min(result,bestending);
        }
        return result;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum =0;
        for(int i=0;i<nums.size();i++){
            totalsum += nums[i];
        }
        int normalsum = maxsum(nums);
        if(normalsum < 0){
            return normalsum;
        }
        return max(maxsum(nums),(totalsum-minsum(nums)));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna