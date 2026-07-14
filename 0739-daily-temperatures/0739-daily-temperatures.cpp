class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        
        stack<int>st;
        int n = nums.size();
        vector<int>ans(n,0);
        
        st.push(n-1);

        for(int i=n-2;i>=0;i--){
            
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] =st.top() -i;
            }
            st.push(i);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna