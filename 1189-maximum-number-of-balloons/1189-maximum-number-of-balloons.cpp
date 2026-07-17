class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        for(auto c :text ){
            have[c]++;
        }
        unordered_map<char,int>need;
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;

        int res = INT_MAX;

        for(auto i : need){
            char c = i.first;
            int fneed =   i.second;
            int fhave = have[c];

            int times = fhave/fneed;

            res = min(res,times);
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna