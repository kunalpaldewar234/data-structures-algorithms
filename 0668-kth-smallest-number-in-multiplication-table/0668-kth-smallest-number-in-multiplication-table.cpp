class Solution {
public:
   int fun(int m, int n, int guess){
    int count = 0;

    for(int i = 1; i <= m; i++){
        count += min(n, guess / i);
    }

    return count;
}
    int findKthNumber(int m,int n, int k) {
        int res = -1;
        
        int low = 1;
        int high = m*n;
        while(low <= high){
            int guess = low + (high-low)/2;
            if(fun(m,n,guess) >= k){
                res = guess;
                high = guess-1;
            }else{
                low = guess+1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna