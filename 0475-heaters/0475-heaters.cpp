class Solution {
public:
    bool cancoverallhouses(vector<int>& houses, vector<int>& heaters, int radius) {

        int i = 0;
        int n = houses.size();

        for (int heater : heaters) {

            while (i < n && houses[i] < heater - radius) {
                return false;
            }

            while (i < n && houses[i] <= heater + radius) {
                i++;
            }

            if (i == n) {
                return true;
            }
        }

        return i == n;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int low = 0;
        int high = max(abs(houses.front() - heaters.back()),
                       abs(houses.back() - heaters.front()));

        int res = high;

        while (low <= high) {

            int guess = low + (high - low) / 2;

            if (cancoverallhouses(houses, heaters, guess)) {
                res = guess;
                high = guess - 1;
            }
            else {
                low = guess + 1;
            }
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna