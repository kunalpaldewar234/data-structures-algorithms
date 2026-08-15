class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int oldcolor = image[sr][sc];
        if(image[sr][sc] == color){
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        int dx[4] ={-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];

                if(nx >= 0 && nx<n && ny >=0  && ny < m && image[nx][ny] == oldcolor){
                    q.push({nx,ny});
                    image[nx][ny] = color;
                }
            }
           
        }
        return image;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna