class Solution {
  public:
    bool canallocate(vector<int>&arr,int stud,int n,long long limit ){
        int k =  1;
        long long page = 0;
        
        for(int i=0;i<n;i++){
            if(page+arr[i] <= limit){
                page += arr[i];
            }else{
                k++;
                page = arr[i];
                if(k > stud){
                    return false;
                }
            }
            }
            return true;
    }
    
    int findPages(vector<int> &arr, int stud) {
        // code here
        int n  = arr.size();
        int res = -1;
        if(n < stud){
            return -1;
        }
        int low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        
        while(low <= high){
            
            long long guess = low + (high-low)/2;
            if(canallocate(arr,stud,n,guess)){
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