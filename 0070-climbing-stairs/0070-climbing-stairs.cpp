class Solution {
public:
    unordered_map<int,int>dp;
    int fun(int i,int n){
        if(i == n){
            return 1;
        }
        if(i > n){
            return 0;
        }
        if(dp.find(i) != dp.end()){
            return dp[i];
        }
        int ans1 = fun(i+1,n);
        int ans2 = fun(i+2,n);
        dp[i] = ans1+ans2;
        return ans1+ans2;
    }
    int climbStairs(int n) {
        return fun(0,n);
    }
};