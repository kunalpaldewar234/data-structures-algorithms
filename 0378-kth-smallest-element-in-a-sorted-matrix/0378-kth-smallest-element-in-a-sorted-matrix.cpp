class Solution {
public:
    int fun(vector<vector<int>>& matrix,int guess){
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1;
        int col = 0;
        int count = 0;
        while(row >= 0 && col < m){
            if(matrix[row][col] <= guess){
                count += row+1;
                col++;
            }else{
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int res = -1;
        int n = matrix.size();        
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        while(low <= high){
            int guess = low + (high-low)/2;
            if(fun(matrix,guess) >= k){
                res = guess;
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