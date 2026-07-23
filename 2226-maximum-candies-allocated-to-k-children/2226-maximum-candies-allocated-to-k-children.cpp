class Solution {
public:
    long long total_child(vector<int>&a,int n,long long max_candies){
        long long child = 0;

        for(int i=0;i<n;i++){
            child += a[i]/ max_candies;
        }
        return child;
    }
    int findhigh(vector<int>&a,int n){
        int ans = INT_MIN;
        for(int i : a){
            ans = max(ans,i);
        }
        return ans;
    }
    int maximumCandies(vector<int>& a, long long k) {
        int res = 0;
        int n = a.size();
        int low = 1;
        int high = findhigh(a,n);

        while(low <= high){
            long long guess = (low+high)/2;
            long long child = total_child(a,n,guess);

            if(child >= k){
                res = guess;
                low = guess+1;
            }else{
                high = guess-1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna