class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store key-value pairs
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                string key = "";
                i++;  // move after '('

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // If key exists, use its value
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } 
                else {
                    ans += "?";
                }

            } 
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna