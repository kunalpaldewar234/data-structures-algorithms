class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;

        for (int i = 0; i < row; i++) {
            int low = 0;
            int high = col - 1;

            while (low <= high) {
                int guess = low + (high - low) / 2;

                if (matrix[i][guess] <= mid) {
                    low = guess + 1;
                } else {
                    high = guess - 1;
                }
            }

            count += low;
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[row - 1][col - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (countLessEqual(matrix, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna