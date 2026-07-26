class Solution {
public:
    bool canshift(vector<int>&weights,int days,int n,long long limit){
        int day = 1;
        long long weight = 0;

        for(int i =0;i<n;i++){
            if(weight+ weights[i] <= limit){
                weight += weights[i];
            }else{
                day++;
                weight = weights[i];
                if(day > days){
                    return false;
                }
                }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n  = weights.size();
        
        long long res = -1;
        int low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL);


        while(low<= high){
            long long guess = low + (high-low)/2;
            if(canshift(weights,days,n,guess)){
                res = guess;
                high = guess-1;
            }else{
                low = guess+1;
            }
        }
        return int(res);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna