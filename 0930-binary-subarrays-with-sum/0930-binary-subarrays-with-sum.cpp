    class Solution {
    public:
        int atmost(vector<int>nums,int goal){
            if (goal < 0) return 0;
            int low =0;
            int high =0;
            int sum =0;
            int count =0;
            while(high<nums.size()){
                sum = sum + nums[high];

                while(sum > goal){
                    sum = sum - nums[low];
                    low++;
                }
                count += (high-low+1); 
                high++;
            }
            return count;
        }
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return atmost(nums,goal)-atmost(nums,goal-1);
        }
    };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna