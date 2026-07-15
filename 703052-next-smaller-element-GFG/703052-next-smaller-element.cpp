class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        
        
        ans[n-1] = -1;
        st.push(arr[n-1]);
        
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna