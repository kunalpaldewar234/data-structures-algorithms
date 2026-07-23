class Solution {
public:
    long long total_hours(vector<int>& a, int n, int speed){
        long long h = 0;
        for(int i = 0; i < n; i++){
            h += a[i] / speed;
            if(a[i] % speed != 0){
                h++;
            }
        }
        return h;
    }

    int findhigh(vector<int>& a, int n){
        int ans = INT_MIN;
        for(int i : a){
            ans = max(ans, i);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        int low = 1;
        int high = findhigh(a, n);
        int res = high;

        while(low <= high){
            int guess = low + (high - low) / 2;
            long long hours = total_hours(a, n, guess);

            if(hours > h){
                low = guess + 1;
            }else{
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna