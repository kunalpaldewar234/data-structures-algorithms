class Solution {
public:
    void fun(vector<int>& nums,int idx,int n,vector<int>&diary,vector<vector<int>>&res){
        if(idx == n){
            res.push_back(diary);
            return;
        }

        // take current element 
        diary.push_back(nums[idx]);
        fun(nums,idx+1,n,diary,res);
        diary.pop_back();


        // skip element 
        fun(nums,idx+1,n,diary,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<int>diary;
        vector<vector<int>>res;
        fun(nums,idx,n,diary,res);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna