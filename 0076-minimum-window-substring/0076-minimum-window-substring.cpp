class Solution {
public:
    bool sahi(vector<int>have,vector<int>needed){
        for(int i=0;i<256;i++){
            if(have[i]<needed[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
    vector<int>needed(256,0);
    vector<int>have(256,0);
    int low =0;
    int high =0;
    int res = INT_MAX;
    int start=0;
    for(int i=0;i<t.length();i++){
        needed[t[i]]++;
    }
    while(high<s.length()){
        have[s[high]]++;
        while(sahi(have,needed)){
            int len = high -low+1;
            if(res>len){
                res = len;
                start = low;
            }
            have[s[low]]--;
            low++;
        }
        high++;
    }
    if(res == INT_MAX){
        return "";
    }else{
        return s.substr(start,res);
    }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna