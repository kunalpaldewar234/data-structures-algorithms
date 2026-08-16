class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        long long  same = 0;
        long long res = 0;
        unordered_map<int,int>f;

        while(high < nums.size()){
            // strore value for high
        same += f[nums[high]];
        f[nums[high]]++;


            while(same >= k){         // vondition sahi hai
            res += nums.size()-high;
            f[nums[low]]--;
            same -= f[nums[low]];
            
           low++;
                
            }
            
            high++;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna