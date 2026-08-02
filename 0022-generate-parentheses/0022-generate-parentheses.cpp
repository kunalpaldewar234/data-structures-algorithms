class Solution {
public:
void fun(int o,int c,int n,string &tmp,vector<string>&res){
    if(o==n && c == n){
        res.push_back(tmp);
        return;
    }
    if(o < n){         // open karna hai
        tmp.push_back('(');
        fun(o+1,c,n,tmp,res);
        tmp.pop_back();
    }
    if(c < o){          // close karna hai
        tmp.push_back(')');
        fun(o,c+1,n,tmp,res);
        tmp.pop_back();
    }
    return;
}
    vector<string> generateParenthesis(int n) {
        int o = 0;
        int c = 0;
        vector<string>res;
        string tmp = "";
        fun(o,c,n,tmp,res);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna