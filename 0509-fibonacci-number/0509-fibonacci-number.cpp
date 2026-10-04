class Solution {
public:
    int fib(int n) {
        // sloving by tabulation
        if(n==0){
            return n;
        }
        int prev = 1;
        int prev_prev = 0;
        int ans;
        for(int i=2;i<=n;i++){
            ans = prev+prev_prev;
            prev_prev = prev;
            prev = ans;
        }
        return ans;
    }
};