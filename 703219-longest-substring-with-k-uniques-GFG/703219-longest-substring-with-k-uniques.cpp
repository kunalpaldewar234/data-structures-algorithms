class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int res = -1;
        int low =0;
        int high =0;
        int n = s.length();
        unordered_map<char, int>f;
        while(high<n){
            f[s[high]]++;
            
            while(f.size()>k){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
            }
            if(f.size()==k){
                int len = high-low+1;
                res = max(len,res);
            }
            high++;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna