class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0;i<row;i++){
            int low = 0;
            int high = col-1;
            while(low <= high){
            int guess = low + (high-low)/2;
           
            if(matrix[i][guess] == target){
                return true;
            }else if(matrix[i][guess] > target){
                high = guess-1;
            }else{
                low = guess+1;
            }
        }
        }
        
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna