/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
#define Node TreeNode
#define null nullptr
#define data val
Node* ans = null;
int fun(Node*node,Node*p,Node*q){
    if(node == null){
        return 0;
    }
    
    int left = fun(node->left,p,q);
    int right = fun(node->right,p,q);
    int self = 0;
    if(node == p || node == q){
         self =1;
    }
    int total = left+self+right;

    if(ans == null && total == 2){
        ans = node;
    }
    return total;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

     fun(root,p,q);
     return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna