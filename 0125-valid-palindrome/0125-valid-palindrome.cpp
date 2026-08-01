class Solution {
public:
    bool fun(string &s, int low, int high) {
        if (low >= high)
            return true;

        if (s[low] != s[high])
            return false;

        return fun(s, low + 1, high - 1);
    }

    bool isPalindrome(string s) {
        string t;

        // Remove non-alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c))
                t += tolower(c);
        }

        return fun(t, 0, t.length() - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna