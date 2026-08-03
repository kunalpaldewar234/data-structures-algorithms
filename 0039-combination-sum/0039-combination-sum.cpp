class Solution {
public:
    void fun(vector<int>& candidates,int idx,int n,int target,vector<int>&sum,vector<vector<int>>&res){
        if(target == 0){
            res.push_back(sum);
            return;
        }
        if(idx == n || target < 0){
            return;
        }
        sum.push_back(candidates[idx]);
        fun(candidates,idx,n,target-candidates[idx],sum,res);
        sum.pop_back();
        fun(candidates,idx+1,n,target,sum,res);
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int idx = 0;
        vector<int>sum;
        vector<vector<int>>res;
        fun(candidates,idx,n,target,sum,res);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna