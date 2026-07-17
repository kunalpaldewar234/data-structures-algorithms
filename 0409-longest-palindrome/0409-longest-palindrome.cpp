class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        bool odd = false;
        int res = 0;
        for(auto i: s){
            f[i]++;
        }

        for(auto i : f){
            int val = i.second;

            if(val % 2 == 0){
                res += val;
            }else{
                odd = true;
                res += val-1;
            }
        }
        if(odd == false){
            return res;
        }

        
        return res+1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna