class Solution {
public:
    void fun(vector<int>& nums,int idx,int n,vector<int>&diary,vector<vector<int>>&res,vector<int>&used){
        if(idx == n){
            res.push_back(diary);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            used[i] =1;
            diary.push_back(nums[i]);
            fun(nums,idx+1,n,diary,res,used);
            diary.pop_back();
            used[i] =0;
        }
        
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        int idx = 0;
        vector<int>diary;
        vector<vector<int>>res;
        vector<int>used(n,0);
        fun(nums,idx,n,diary,res,used);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna