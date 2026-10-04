class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int prev_prev = 1;
        int prev = 2;
        for(int i=3;i<=n;i++){
            int ans = prev+prev_prev;
            prev_prev =prev;
            prev =ans;
        }
        return prev;
    }
};