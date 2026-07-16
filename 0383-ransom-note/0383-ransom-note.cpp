class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char,int>f1;
      unordered_map<char,int>f2;

      for(auto ch :magazine){
        f1[ch]++;
      }

      for(auto ch : ransomNote){
        f2[ch]++;
      }

      for(auto ch : f2){
        if(f1.find(ch.first) == f1.end()){
            return false;
        }
        if(f1[ch.first] < ch.second){
            return false;
        }
        
      }
      return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna