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
Node* prev = null;
bool res = true;
void fun(Node* root){
    if(root == null){
        return;
    }
    fun(root->left);
    if(prev == null){
        prev = root;
    }else{
        if(root->data <= prev->data){
            res = false;
        }
        prev = root;
    }
    fun(root->right);

    return ;
}
    bool isValidBST(TreeNode* root) {
        fun(root);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna