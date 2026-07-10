class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum  = 0;
        
        unordered_map<int,int>firstindex;
        firstindex[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem  = sum % k;
            if(rem < 0){
                rem = rem +k;
            }
            if(firstindex.find(rem)!=firstindex.end()){
                if(i-firstindex[rem] >= 2){
                    return true;
                }
            }else{
                firstindex[rem] = i;
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna