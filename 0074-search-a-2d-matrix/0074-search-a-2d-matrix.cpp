class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = rows*col-1;
        
        while(low <= high){
            int guess = low + (high-low)/2;
            int r = (guess/col);
            int c = (guess%col);
            if(matrix[r][c] == target){
                return true;
            }else if(matrix[r][c] > target){
                high = guess-1;
            }else{
                low = guess+1;
            }
        
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna