class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int res = 0;
    unordered_map<int,int>f;
    int low =0;
    int high =0;

    while(high<nums.size()){
        f[nums[high]]++;

        while(f[0] > 1){
            f[nums[low]]--;
            if(f[nums[low]]==0){
                f.erase(nums[low]);
            }
            low++;
        }
        int len = high -low;
        res = max(len,res);
        high++;
    }  
    return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna