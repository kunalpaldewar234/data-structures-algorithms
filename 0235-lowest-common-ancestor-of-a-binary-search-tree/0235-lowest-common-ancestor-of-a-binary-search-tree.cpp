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
void fun(Node*node,Node*p,Node*q){
    if(node == null){
        return;
    }
    if(node == p || node==q){
        ans  = node;
        return;
    }else if(node->data < p->data){
        fun(node->right,p,q);
    }else if(node->data > q->data){
        fun(node->left,p,q);
    }else{
        ans = node;
        return;
    }
    return;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->data < q->data){
            fun(root,p,q);
        }else{
            fun(root,q,p);
        
        }
       return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna