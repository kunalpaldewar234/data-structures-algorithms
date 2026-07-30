class Solution {
  public:
    class Node{
        public:
        int value;
        int row ;
        int col ;
        
        Node(int v,int r,int c){
            value = v;
            row = r;
            col = c;
        }
    };
    struct cmp{
        bool  operator()(Node &a,Node &b){
            return a.value > b.value;
        }
    };
    
    vector<int> mergeArrays(vector<vector<int>> &a) {
        // Code here
    int n = a.size();
    int m = a[0].size();
    
    priority_queue<Node,vector<Node>,cmp>pq;
    for(int i=0;i<n;i++){
        pq.push({a[i][0],i,0});
    }
    vector<int>res;
    while(!pq.empty()){
        Node n = pq.top();
        pq.pop();
        int v = n.value;
        int row = n.row;
        int col = n.col;
        res.push_back(v);
        if(col < m-1){
            pq.push({a[row][col+1],row,col+1});
        }
    }
    return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna