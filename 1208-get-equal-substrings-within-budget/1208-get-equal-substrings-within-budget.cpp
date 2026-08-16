class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int low = 0;
        int high =0;
        int res = 0;
        int cost = 0;
        
        while(high < s.size()){
            cost += abs(s[high]-t[high]);

            while(cost > maxCost){
                cost -= abs(s[low]-t[low]);
                low++;
            }

            int len = high -low+1;
            res = max(len,res);
            high++;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna