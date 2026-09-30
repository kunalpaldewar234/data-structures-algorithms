class Solution {
public:
int dx[4] ={-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(vector<vector<int>>& image, int x, int y,int n,int m,int color,int oldcolor){
    image[x][y] = color;
    for(int k =0;k<4;k++){
        int nx = x + dx[k];
        int ny = y+dy[k];

    if(nx >= 0 && nx<n && ny >=0  && ny < m && image[nx][ny] == oldcolor){
                    
                    image[nx][ny] = color;
                    dfs(image,nx,ny,n,m,color,oldcolor);
    }
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int oldcolor = image[sr][sc];
        if(image[sr][sc] == color){
            return image;
        }
        dfs(image,sr,sc,n,m,color,oldcolor);
        return image;
    }
};