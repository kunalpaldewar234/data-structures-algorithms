class Solution {
public:
    int atmost(vector<int>nums,int k){
        int oddcount =0;
        int ans =0;
        int low =0;
        int high =0;

        while(high<nums.size()){
            if(nums[high]%2==1){
            oddcount++;
            }
        while(oddcount>k){
            if(nums[low]%2==1){
                oddcount--;
            }
            low++;
        }
        ans += (high-low+1);
        
        high++;
    }
    return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna