

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string best_res = "";

        // Try matching target[0...i-1] exactly
        vector<int> cur_freq = freq;
        for (int i = 0; i < n; ++i) {
            // Try picking a character strictly greater than target[i] at position i
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (cur_freq[c] > 0) {
                    // Build candidate string
                    string candidate = target.substr(0, i);
                    candidate += (char)('a' + c);
                    
                    vector<int> rem_freq = cur_freq;
                    rem_freq[c]--;

                    // Append remaining characters in ascending order
                    for (int j = 0; j < 26; ++j) {
                        candidate.append(rem_freq[j], 'a' + j);
                    }

                    if (best_res == "" || candidate < best_res) {
                        best_res = candidate;
                    }
                }
            }

            // Consume target[i] for the next position
            if (cur_freq[target[i] - 'a'] > 0) {
                cur_freq[target[i] - 'a']--;
            } else {
                break; // Cannot match prefix target[0...i]
            }
        }

        return best_res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna