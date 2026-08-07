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
bool sameTree(Node* root,TreeNode* subRoot){
    if(root == null && subRoot== null) return true;
    if(root == null || subRoot== null) return false;
    if(root->data != subRoot->data) return false;

    bool r1 = sameTree(root->left ,subRoot->left);
    bool r2 = sameTree(root->right,subRoot->right);

    return (r1 && r2);
}

bool fun(Node* root,Node* subRoot){
     if (root == nullptr)
        return false;

    if(sameTree(root,subRoot)){
        return true;
    }
    return fun(root->left,subRoot) || fun(root->right, subRoot);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return fun(root,subRoot);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna