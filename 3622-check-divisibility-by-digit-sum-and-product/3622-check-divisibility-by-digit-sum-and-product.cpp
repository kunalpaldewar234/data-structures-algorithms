class Solution {
public:

    int fun(int n) {
        int sum = 0;

        while (n > 0) {
            int dig = n % 10;
            sum += dig;
            n /= 10;
        }

        return sum;
    }

    int fun2(int n) {
        int prod = 1;

        while (n > 0) {
            int dig = n % 10;
            prod *= dig;
            n /= 10;
        }

        return prod;
    }

    bool checkDivisibility(int n) {
        int sum = fun(n);
        int prod = fun2(n);

        
        if (n % (sum+prod) == 0){
             return true;
        }
           

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna