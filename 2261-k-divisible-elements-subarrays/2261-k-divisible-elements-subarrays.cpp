class Solution {
public:
set<vector<int>>s;
int atmost(vector<int>nums,int k,int p){
    int low =0;
    int high = 0;
    
    int count = 0;
    int divisible = 0;
    while(high < nums.size()){
        if(nums[high] % p == 0){
            divisible++;
        }
            
        while( divisible > k){
            
            if(nums[low] % p == 0){
                divisible--;
            }
            low++;
        }
        vector<int>temp;
        for(int i=high;i>= low;i--){
            temp.push_back(nums[i]);
            s.insert(temp);
        }
        high++;
    }
    return s.size();

}
    int countDistinct(vector<int>& nums, int k, int p) {
        return atmost(nums,k,p);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna