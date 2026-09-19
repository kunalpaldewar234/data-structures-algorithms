class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dest(n,1e8);
        dest[src] = 0;
        for(int i=0;i<k+1;i++){
            vector<int>temp = dest;
            for(int j=0;j<flights.size();j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int wt = flights[j][2];

                if(temp[s] != 1e8 && temp[d] > dest[s]+wt){
                    temp[d] = dest[s]+wt;
                }
            }
            dest = temp;
        }
        if(dest[dst] == 1e8){
            return -1;
        }else{
            return dest[dst];
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna