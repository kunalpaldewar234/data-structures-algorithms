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
void fun(Node* node,vector<vector<int>>&res){
    queue<Node*>q;
    if(node == null)
        return;
    q.push(node);
    bool left_toright = 1;
    while(!q.empty()){
        int lvlsize = q.size();
        vector<int>tmp(lvlsize);
        int first = 0;
        int last = tmp.size()-1;
        while(lvlsize--){
            Node* t = q.front();
            q.pop();
            if(left_toright){
                tmp[first] = t->data;
                first++;
            }else{
                tmp[last] = t->data;
                last--;
            }
            if(t->left != null){
                q.push(t->left);
            }
            if(t->right != null){
                q.push(t->right);
            }
        }
        res.push_back(tmp);
        left_toright = 1 - left_toright;
        
    }
    return;
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        fun(root,res);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna