class Solution {
public:
    int maximumLengthSubstring(string s) {
        int low = 0;
        int high = 0;
        int res = -1;
        unordered_map<char,int>f;
        
        while(high<s.length()){
             f[s[high]]++;
            while(f[s[high]] >2 ){
                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;
            }
            int len = high-low+1;
            res = max(len,res);
            high++;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna