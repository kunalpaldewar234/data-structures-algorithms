class Solution {
public:
int x[4] ={-1,1,0,0};
int y[4] ={0,0,-1,1};
bool isvalid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>= m){
        return false;
    }
    return true;
}
void dfs(vector<vector<char>>&grid,int n,int m, int i,int j,vector<vector<bool>>&vis){
    vis[i][j] = 1;

    for(int k=0;k<4;k++){
        int row = i + x[k];
        int col = j + y[k];
        if(isvalid(row,col,n,m) && vis[row][col] == 0 && grid[row][col] == '1'){
            dfs(grid,n,m,row,col,vis);
        }
        
    }
    return;
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i,j;
        int res = 0;
        vector<vector<bool>>ves(n);
        for(int i=0;i<n;i++){
            vector<bool>t(m,0);
            ves[i] = t;
        }
        for( i = 0;i<n;i++){
            for( j= 0;j<m;j++){
                if(grid[i][j] == '1' && ves[i][j] == 0){
                    dfs(grid,n,m,i,j,ves);
                    res += 1;
                }
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna