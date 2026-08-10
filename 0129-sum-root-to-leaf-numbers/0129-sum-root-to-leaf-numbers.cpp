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
int res = 0;
void fun(Node*root,int sum){
    if(root == null){
        return;
    }
    sum = (sum*10 )+root->data;

    if(root->left == null && root->right == null){
        res += sum;
    }
    fun(root->left,sum);
    fun(root->right,sum);
    return;
}
    int sumNumbers(TreeNode* root) {
        fun(root,0);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna