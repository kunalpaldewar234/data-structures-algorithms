class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start or destination is blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // 8 directions
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        queue<pair<pair<int,int>,int>> q;

        q.push({{0,0},1});
        grid[0][0] = 1;

        while(!q.empty()) {

            auto p = q.front();
            q.pop();

            int x = p.first.first;
            int y = p.first.second;
            int dist = p.second;

            // Destination reached
            if(x == n-1 && y == n-1)
                return dist;

            for(int i = 0; i < 8; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n &&
                   ny >= 0 && ny < n &&
                   grid[nx][ny] == 0) {

                    grid[nx][ny] = 1;

                    q.push({{nx,ny}, dist + 1});
                }
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna