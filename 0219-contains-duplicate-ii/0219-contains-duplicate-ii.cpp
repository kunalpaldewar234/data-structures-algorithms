class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int low =0;
        int high = 0;
        unordered_set<int>st;

        while(high<nums.size()){
            while(high-low+1 > k+1){
                st.erase(nums[low]);
                low++;
            }
            if(st.count(nums[high])){
                return true;
            }

            st.insert(nums[high]);

            
            
            high++;
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna