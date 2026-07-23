class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int guess = (low + high) / 2;

            if (nums[guess] == target) {
                return guess;
            }

            // Part 1 : guess is in left sorted part
            if (nums[guess] >= nums[n - 1]) {

                if (nums[guess] < target) {
                    // right jana hai
                    low = guess + 1;
                } else {
                    if (target >= nums[0]) {
                        // left jana hai
                        high = guess - 1;
                    } else {
                        // right jana hai
                        low = guess + 1;
                    }
                }
            }

            // Part 2 : guess is in right sorted part
            else {

                if (nums[guess] > target) {
                    // left jana hai
                    high = guess - 1;
                } else {
                    if (target <= nums[n - 1]) {
                        // right jana hai
                        low = guess + 1;
                    } else {
                        // left jana hai
                        high = guess - 1;
                    }
                }
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna