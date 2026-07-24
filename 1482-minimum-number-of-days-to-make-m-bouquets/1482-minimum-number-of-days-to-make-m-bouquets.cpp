class Solution {
public:

    bool canMakeflower(vector<int>& a,int m,int k,int day){
        int bouquets = 0;
        int count = 0;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i] <= day){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }else{
                count = 0;
            }
        }
        return bouquets >=m;
    }
    int findhigh(vector<int>&a,int n){
        int ans = INT_MIN;
        for(int i : a){
            ans = max(ans,i);
        }
        return ans;
    }
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();
        int low = 1;
        int high = findhigh(a,n);
        int res = -1;
         if ((long long)m * k > n)
         return -1;

        while(low <= high){
            int guess = low+ (high-low)/2;
            if(canMakeflower(a,m,k,guess)){
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