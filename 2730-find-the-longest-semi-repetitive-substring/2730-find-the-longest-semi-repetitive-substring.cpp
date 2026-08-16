class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int low = 0;
        int high = 0;
        int same = 0;
        int res = 0;
    


        while(high < s.length()){
            if(high > 0 && s[high-1] == s[high]){
                same++;
            }
            while(same > 1){
                if( s[low] == s[low+1]){
                    same--;
                }
                low++;
            }
            int len = high-low+1;
            res = max(res,len);
            high++;
        }
        return res;
    }

};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna