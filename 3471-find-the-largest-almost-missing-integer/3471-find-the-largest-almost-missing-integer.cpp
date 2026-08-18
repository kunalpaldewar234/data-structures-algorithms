class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int case1 = -1;
        int case2 = 0;

        unordered_map<int, int> f;

        for (int x : nums) {
            f[x]++;
        }

        for (int i = 0; i < n; i++) {
            if (f[nums[i]] == 1) {
                case1 = max(case1, nums[i]);
            }

            case2 = max(case2, nums[i]);
        }

        if (k == 1) {
            return case1;
        }

        if (k == n) {
            return case2;
        }

        int ans = -1;

        if (f[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (f[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna