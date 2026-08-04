class Solution {
public:
    void fun(vector<int>& candidates, int target,int n,int idx,int sum,vector<int>&diary,
    vector<vector<int>>&res){
        if(idx == n){
            if(sum == target){
                res.push_back(diary);
            }
            return;
        }
        if(sum > target) return;
        // Take current element
        diary.push_back(candidates[idx]);
        sum += candidates[idx];
        fun(candidates,target,n,idx+1,sum,diary,res);
        diary.pop_back();
        sum -= candidates[idx];

        // skip ALL Duplicate element
        int next = idx+1;
        while(next < n && candidates[next] == candidates[idx] ){
          next++;
        }
        fun(candidates,target,n,next,sum,diary,res);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        int idx = 0;
        int sum = 0;
        vector<int>diary;
        vector<vector<int>>res;
        fun(candidates,target,n,idx,sum,diary,res);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna