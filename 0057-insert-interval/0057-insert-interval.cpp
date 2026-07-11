class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>>res;
        sort(arr.begin(),arr.end());
        int start1 = arr[0][0];
        int end1 = arr[0][1];

        for(int i=1;i<arr.size();i++){
            int start2 = arr[i][0];
            int end2 = arr[i][1];

            if(start2 <= end1){
                start1 = start1;
                end1 = max(end1,end2);
                continue;
            }

            res.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
        }

        res.push_back({start1,end1});
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        bool insert = false;
        for(int i=0;i<intervals.size();i++){
           int start = intervals[i][0];

            if(insert == false && start >= newInterval[0]){
                ans.push_back(newInterval);
                insert = true;
            }
            ans.push_back(intervals[i]);
        }
       if (!insert) {
    ans.push_back(newInterval);
}

        return merge(ans);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna