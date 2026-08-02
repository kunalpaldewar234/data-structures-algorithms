class Solution {
public:
    unordered_map<char,string>f;
    void fun(string digits,int idx,int n,string &diary,vector<string>&res){
        if(idx == n){
            res.push_back(diary);
            return;
        }
        string choice = f[digits[idx]];
        for(int j =0;j<choice.length();j++){
            diary.push_back(choice[j]);
            fun(digits,idx+1,n,diary,res);
            diary.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    f['2'] = "abc";
    f['3'] = "def";
    f['4'] = "ghi";
    f['5'] = "jkl";
    f['6'] = "mno";
    f['7'] = "pqrs";
    f['8'] = "tuv";
    f['9'] = "wxyz";
    int n = digits.length();
    int idx = 0;
    string diary ="";
    vector<string>res;
    fun(digits,idx,n,diary,res);
    return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna