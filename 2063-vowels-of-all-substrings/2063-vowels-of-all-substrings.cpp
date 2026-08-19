class Solution {
public:
    bool isvovel(char c){
        if(c == 'a' ||  c== 'e' || c=='i' || c == 'o' || c == 'u'){
            return true;
        }
        return  false;
    }
    long long countVowels(string word) {
        unordered_map<char,int>f;
        int low = 0;
        int high = 0;
        long long res =0;

        while(high < word.length()){
            
            if(isvovel(word[high])){
             res += (long long)(high + 1) * (word.length() - high);
            }
            high++;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna