class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        int low = 0;
        int high = k - 1;
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int res = sum;

        while (high < n - 1) {
            low++;
            high++;

            sum -= nums[low - 1];
            sum += nums[high];

            res = max(res, sum);
        }

        return (double)res / k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna