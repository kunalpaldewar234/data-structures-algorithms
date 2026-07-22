class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<= high){
            int guess = (low+high)/2;
            if(nums[guess] == target){
                return guess;
            }

            if(nums[low] <= nums[guess]){       // left sorted array;
                if(nums[low] <= target && target < nums[guess]){
                    high = guess-1;
                }else{
                    low = guess+1;
                }
            }else{ // Right half is sorted
                if(nums[guess] < target && target <= nums[high]){
                    low = guess+1;
                }else{
                    high = guess-1;
                }
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna