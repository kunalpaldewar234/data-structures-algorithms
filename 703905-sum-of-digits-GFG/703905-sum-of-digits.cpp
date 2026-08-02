class Solution {
  public:
    int sumOfDigits(int n) {
        // code here
        if(n == 0){
            return 0;
        }
        
        int d = n%10;
        n = n/10;
        int ans = sumOfDigits(n);
        return ans+d;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna