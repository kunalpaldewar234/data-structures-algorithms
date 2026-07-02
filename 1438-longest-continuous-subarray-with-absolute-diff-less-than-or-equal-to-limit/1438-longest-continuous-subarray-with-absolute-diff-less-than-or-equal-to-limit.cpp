class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = INT_MIN;
        int low =0;
        int high =0;
        multiset<int>ms;
        while(high<nums.size()){
            ms.insert(nums[high]);
            
            while(abs(*ms.rbegin()-*ms.begin())>limit){
                ms.erase(ms.find(nums[low]));
                low++;
            }
           res = max(res,high-low+1);
           high++;
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna