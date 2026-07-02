class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = -1;
        int low =0;
        int high =0;
        unordered_map<int,int>f;
        while(high<fruits.size()){
            f[fruits[high]]++;

            while(f.size()>2){
                f[fruits[low]]--;
                if(f[fruits[low]]==0){
                    f.erase(fruits[low]);
                }
                low++;
            }
            
            int len = high-low+1;
            res = max(len,res);
            high++;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna