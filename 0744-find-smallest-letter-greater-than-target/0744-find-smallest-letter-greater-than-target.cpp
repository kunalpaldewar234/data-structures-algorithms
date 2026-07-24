class Solution {
public:
    char nextGreatestLetter(vector<char>& let, char target) {
        int n  = let.size();
        char res = let[0];

        int low = 0;
        int high = n-1;

        while(low <= high){
            int guess = low + (high-low)/2;

            if(let[guess] >target){
                res = let[guess];
                high = guess-1;
            }else{
                low = guess+1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna