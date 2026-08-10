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
#define data val
#define null nullptr
bool res = false;
void fun(Node* root,int sum,int targetsum){
    if(root == null){
        return;
    }
    sum += root->data;
    if(root->left == null && root->right == null){
        if(sum == targetsum){
            res = true;
        }
        return ;
    }
    fun(root->left,sum,targetsum);
    fun(root->right,sum,targetsum);
    return;
}
    bool hasPathSum(TreeNode* root, int targetsum) {
        fun(root,0,targetsum);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna