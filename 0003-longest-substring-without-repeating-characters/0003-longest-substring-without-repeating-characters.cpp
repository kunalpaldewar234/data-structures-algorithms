class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low =0;
        int high =0;
        unordered_map<char,int>f;
        int res = 0;

        while(high<s.length()){
            f[s[high]]++;
            int k = high-low+1;
            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
                k= high-low+1;
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