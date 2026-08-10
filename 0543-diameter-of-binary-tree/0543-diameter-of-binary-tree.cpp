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
int res = 0;
int fun(Node* root){
    if(root == null){
        return 0;
    }

    int left = fun(root->left);
    int right = fun(root->right);

    int sum = left+right;
    res = max(res,sum);

    return 1+max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna