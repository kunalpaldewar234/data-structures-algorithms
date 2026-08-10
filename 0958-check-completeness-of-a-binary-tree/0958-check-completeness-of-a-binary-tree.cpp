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
bool null_found = false;
bool fun(Node* root){
    if(root == null){
        return true;
    }

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* t = q.front();
        q.pop();

        if(t == null){
            null_found = true;
        }else{
            if(null_found){
                return  false;
            }
            q.push(t->left);
            q.push(t->right);
        }
        
    }

    return true;
}
    bool isCompleteTree(TreeNode* root) {
        return fun(root);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna