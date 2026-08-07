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

void fun(Node* node,vector<int>&res){
        if(node == null){
            return;
        }
        queue<Node*>q;
        q.push(node);

        while(!q.empty()){
            int max_no = INT_MIN;
            int lvlsize = q.size();
            while(lvlsize--){
                Node* t = q.front();
                q.pop();
                max_no = max(max_no,t->data);
                if(t->left != null){
                    q.push(t->left);
                }
                if(t->right != null){
                    q.push(t->right);
                }
            }
            res.push_back(max_no);
        }
        return;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        fun(root,res);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna