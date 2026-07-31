class Solution {
public:
    struct cmp{
        bool operator()(pair<int,char>&a,pair<int,char>&b){
            return a.first < b.first;
        }
    };
    int leastInterval(vector<char>& tasks, int gap) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp>pq;
        unordered_map<char,int>freq;
        unordered_map<char,int>free;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }
        for(auto i : freq){
            pq.push({i.second,i.first});
        }
        int seat = 1;
        while(!pq.empty()){
            vector<pair<int,char>>pulled; // cona ma khada ho jao
            while(!pq.empty()){
                pair<int,char>p = pq.top();
                pq.pop();
                int f = p.first;
                char child = p.second;
                if(free[child] <= seat){
                    if(f > 1){
                        pq.push({p.first-1,child});
                    }
                     free[child] = seat+gap+1;
                        break;
                }else{
                    pulled.push_back(p);
                }
            }// checking vala while;
            for(int i=0;i<pulled.size();i++){
                pq.push(pulled[i]);
            }
            seat++;
        }
        return seat-1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna