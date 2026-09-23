class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        // If target < 0, impossible
        if (target < 0) {
            return -1;
        }

        // If target == 0, remove all elements
        if (target == 0) {
            return n;
        }

        int low = 0;
        int sum = 0;
        int maxLen = -1;

        for (int high = 0; high < n; high++) {
            sum += nums[high];

            while (sum > target) {
                sum -= nums[low];
                low++;
            }

            if (sum == target) {
                maxLen = max(maxLen, high - low + 1);
            }
        }

        if (maxLen == -1) {
            return -1;
        }

        return n - maxLen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna