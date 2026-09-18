class Solution {
public:
    bool isvalid(int i,int j,int n){
        if(i<0 || j<0 || i>=n || j>=n){
            return false;
        }
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>res(n);
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};
        for(int i=0;i<n;i++){
            vector<int>t(n,INT_MAX);
            res[i] = t;
        }
         priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>>pq;
        res[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            int curr_time = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if(curr_time > res[row][col]){
                continue;
            }
            for(int k=0;k<4;k++){
                int r = row+x[k];
                int c = col+y[k];
                if(!isvalid(r,c,n)){
                    continue;
                }
                int maxtime = max(curr_time,grid[r][c]);
                if(maxtime < res[r][c]){
                    res[r][c] = maxtime;
                    pq.push({maxtime,{r,c}});
                }
            }
        }
        return res[n-1][n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna