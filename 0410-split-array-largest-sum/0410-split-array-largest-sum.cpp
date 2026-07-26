class Solution {
public:
    bool cansplit(vector<int>& nums, int k,int n,long long limit){
        int count = 1;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            if(sum+nums[i] <= limit){
                sum += nums[i];
            }else{
                count++;
                sum = nums[i];
                if(count > k){
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k){
            return -1;
        }
        int res = -1;
        long long low = *max_element(nums.begin(),nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while(low <= high){
            long long guess = low +(high - low)/2;
            if(cansplit(nums,k,n,guess)){
                res = guess;
                high = guess-1;
            }else{
                low = guess+1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna