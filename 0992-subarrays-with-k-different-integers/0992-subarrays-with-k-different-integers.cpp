class Solution {
public:
    int atmost(vector<int>nums,int k ){
        int low =0;
        int high =0;
        unordered_map<int,int>f;
        int count =0;

        while(high <nums.size()){
            f[nums[high]]++;
            while(f.size()>k){
                f[nums[low]]--;
                if(f[nums[low]]==0){
                    f.erase(nums[low]);
                }
                low++;
            }

            count = count + (high-low+1);
            high++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna