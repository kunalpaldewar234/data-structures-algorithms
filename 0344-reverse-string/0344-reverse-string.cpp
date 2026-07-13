class Solution {
public:
    void reverseString(vector<char>& s) {
    stack<char>st;
    
    vector<char>res;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
    int i=0;
    while(!st.empty()){
        s[i++] = st.top();
        st.pop();
        
    }
    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna