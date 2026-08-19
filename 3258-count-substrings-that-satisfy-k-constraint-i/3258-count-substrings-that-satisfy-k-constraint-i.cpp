class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        unordered_map<char,int>f;
        int low = 0;
        int high = 0;
        int res = 0;
        int n = s.length();

        while(high < n){
            f[s[high]]++;

            while(f['0'] >k && f['1'] >k){
                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;
            }
            res = res + (high-low+1);
            high++;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna