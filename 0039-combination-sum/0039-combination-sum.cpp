class Solution {
public:
    void fun(vector<int>& candidates,int idx,int n,int target,vector<int>&diary,vector<vector<int>>&res,int sum){
        if(idx == n){
            if(sum == target){
                res.push_back(diary);
            }
            return;
        }
        fun(candidates,idx+1,n,target,diary,res,sum); // skip the current element 

        if(sum+candidates[idx] <= target){
            diary.push_back(candidates[idx]);
            sum += candidates[idx];
            fun(candidates,idx,n,target,diary,res,sum);
            diary.pop_back();
            sum -= candidates[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int idx = 0;
        int sum =0 ;
        vector<int>diary;
        vector<vector<int>>res;
        fun(candidates,idx,n,target,diary,res,sum);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna