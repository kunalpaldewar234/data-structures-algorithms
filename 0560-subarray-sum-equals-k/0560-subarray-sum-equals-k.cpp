class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int sum =0;
        f[0] = 1;
        int result = 0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            int ques = sum-k;
            int freq = f[ques];

            result += freq;
            f[sum]++;
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna