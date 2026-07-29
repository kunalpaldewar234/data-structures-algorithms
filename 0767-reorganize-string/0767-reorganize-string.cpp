class Solution {
public:
    struct cmp {
        bool operator()(pair<int,char> &a, pair<int,char> &b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;   // max heap
        }
    };

    string reorganizeString(string s) {

        unordered_map<char,int> f;

        for(char ch : s)
            f[ch]++;

        priority_queue<pair<int,char>, vector<pair<int,char>>, cmp> pq;

        for(auto it : f)
            pq.push({it.second, it.first});

        string res = "";

        pair<int,char> prev = {0, '#'};   // previous character

        while(!pq.empty()) {

            pair<int,char> p = pq.top();
            pq.pop();

            res.push_back(p.second);
            p.first--;

            // push previous character back into heap
            if(prev.first > 0)
                pq.push(prev);

            prev = p;
        }

        if(res.length() != s.length())
            return "";

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna