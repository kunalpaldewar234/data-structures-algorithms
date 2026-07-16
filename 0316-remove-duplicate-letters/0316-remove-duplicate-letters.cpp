class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(256,0);
        vector<bool>visited(256,false); 
        stack<int>st;

        for(char ch : s){
            freq[ch]++;
        }

        for(char ch : s){
            freq[ch]--;

            if(visited[ch]){
                continue;
            }
            while(!st.empty() && st.top() > ch && freq[st.top()]>0){
                visited[st.top()] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch] = true;
        }

        string ans;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna