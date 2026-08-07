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
bool fun(Node* p,Node* q){
    if(p== null && q==null) return true;
    if(p == null || q== null ) return false;
    if(p->data != q->data) return false;


    bool r1 = fun(p->left,q->left);
    bool r2 = fun(p->right,q->right);

    return (r1 && r2);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p,q);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna