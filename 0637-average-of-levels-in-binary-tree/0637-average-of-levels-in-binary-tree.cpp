/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
#define Node TreeNode
#define null nullptr
#define data val
void fun(Node* node,vector<double>&res){
    if(node == null){
        return;
    }
    queue<Node*>q;
    q.push(node);
    
    while(!q.empty()){
        double sum = 0;
        int lvlsize = q.size();
        int s = lvlsize;
        while(lvlsize--){
            Node* t = q.front();
            q.pop();
            sum += t->data;

            if(t->left != null){
                q.push(t->left);
            }
            if(t->right != null){
                q.push(t->right);
            }
        }
        double avg = sum/s;

        res.push_back(avg);

    }
    return;
}
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        fun(root,res);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna