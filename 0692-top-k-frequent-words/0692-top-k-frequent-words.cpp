class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        int n = words.size();

        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

        unordered_map<string,int> f;

        for (int i = 0; i < n; i++) {
            f[words[i]]++;
        }

        for (auto i : f) {

            int freq = i.second;
            string element = i.first;

            pair<int,string> curr = {freq, element};

            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            if (curr.first > pq.top().first ||
               (curr.first == pq.top().first &&
                curr.second < pq.top().second)) {

                pq.pop();
                pq.push(curr);
            }
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna