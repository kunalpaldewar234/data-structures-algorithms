class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int low =0;
        int high =0;
        int res = 0;
        unordered_map<int,int>f;

        while(high<nums.size()){
            f[nums[high]]++;

            while(f[nums[high]]>k){
                f[nums[low]]--;
                if(f[nums[low]]==0){
                    f.erase(nums[low]);
                }
                low++;
            }
            int len = high-low+1;
            res = max(len,res);
            high++;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna