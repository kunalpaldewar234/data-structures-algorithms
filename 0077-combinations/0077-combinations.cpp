class Solution {
public:
    void fun(int n, int k,int idx,vector<int>&diary,vector<vector<int>>&res){
        
        if(diary.size() == k){
            res.push_back(diary);
            return;
        }
        if(idx > n){
            return;
        }
        diary.push_back(idx);
        fun(n,k,idx+1,diary,res);
        diary.pop_back();

        fun(n,k,idx+1,diary,res);
        
    }
    vector<vector<int>> combine(int n, int k) {
        int idx = 1;
        vector<int>diary;
        vector<vector<int>>res;
        fun(n,k,idx,diary,res);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna