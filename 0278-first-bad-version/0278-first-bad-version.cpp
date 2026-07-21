// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int left = 1;
        long int right = n;

        while(left<right){
            long int mid = left+(right-left)/2;

            if(!isBadVersion(mid)){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna