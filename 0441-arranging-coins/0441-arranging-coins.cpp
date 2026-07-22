class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0;
        int high = n;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long coins = 1LL * mid * (mid + 1) / 2;

            if (coins <= n) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna