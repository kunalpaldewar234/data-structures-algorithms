class Solution {
public:
string fun(string s,int k){
    int n = s.length();
        int low =0;
        int high = 0;
        unordered_map<char,int>f;
        int res = INT_MAX;
        string ans = "";

        while(high<s.length()){
            f[s[high]]++;
            vector<int>tmp;
            while(f['1'] == k){
                int len = high-low+1;
                string temp = s.substr(low,len);
                if(res>len){
                    res = len;
                    ans = temp;
                }else if(res == len && temp < ans){
                    ans = temp;
                }

                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;
            }
            high++;
            
            }
        return ans;

}
    string shortestBeautifulSubstring(string s, int k) {
        // we have to  find exactely k

        return fun(s,k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna