class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMasks;
        
        // Map reserved seats to a bitmask for each row (only seats 2 through 9 matter)
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }
        
        // Maximum possible allocations assuming all n rows are empty
        int totalGroups = n * 2;
        
        // Bitmask representations for the 4-seat blocks
        // Seats 2-5 -> bits 0,1,2,3 -> 0b00001111 (15)
        // Seats 4-7 -> bits 2,3,4,5 -> 0b00111100 (60)
        // Seats 6-9 -> bits 4,5,6,7 -> 0b11110000 (240)
        int leftMask = 15;
        int middleMask = 60;
        int rightMask = 240;
        
        for (const auto& [row, mask] : rowMasks) {
            bool leftFree = (mask & leftMask) == 0;
            bool rightFree = (mask & rightMask) == 0;
            bool middleFree = (mask & middleMask) == 0;
            
            if (leftFree && rightFree) {
                // Fits 2 groups -> no deduction
                continue;
            } else if (leftFree || rightFree || middleFree) {
                // Fits 1 group -> deduct 1
                totalGroups -= 1;
            } else {
                // Fits 0 groups -> deduct 2
                totalGroups -= 2;
            }
        }
        
        return totalGroups;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna