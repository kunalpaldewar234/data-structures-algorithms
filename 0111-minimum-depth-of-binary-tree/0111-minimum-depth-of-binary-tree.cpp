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

int fun(Node* root){
    if(root == null){
        return 0;
    } 
    // leaf node
    if(root->left == null && root->right == null){
        return 1;
    }

    // node with only one child
    //left child 
    if(root->right == null){
        return 1 + fun(root->left);
    }
    // right child
    if(root->left == null){
        return 1+ fun(root->right);
    }
// having both child 

    return 1+min(fun(root->left),fun(root->right));
    
}
    int minDepth(TreeNode* root) {
        return fun(root);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna