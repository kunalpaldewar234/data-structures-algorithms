class Solution {
public:
    string removeDuplicates(string s, int k) {
       stack<pair<char,int>>st;
       string res;

       int i=0;
       while(i<s.length() ){
        if(st.empty() || st.top().first != s[i]){
            st.push({s[i],1});
        }else{
            st.top().second++;
            if(st.top().second == k){
                st.pop();
            }
        }
        i++;
       } 
       while(!st.empty()){
        int cnt = st.top().second;
        char ch = st.top().first;
        st.pop();

        while(cnt){
            res.push_back(ch);
            cnt--;
        }

       }
       reverse(res.begin(),res.end());
       return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna