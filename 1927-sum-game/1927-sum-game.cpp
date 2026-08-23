class Solution {
 public:
  bool sumGame(string num) {
    const int n = num.length();
    double ans = 0.0;

    for (int i = 0; i < n / 2; ++i)
      ans += getExpectation(num[i]);

    for (int i = n / 2; i < n; ++i)
      ans -= getExpectation(num[i]);

    return ans != 0.0;
  }

 private:
  double getExpectation(char c) {
    return c == '?' ? 4.5 : c - '0';
  }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna