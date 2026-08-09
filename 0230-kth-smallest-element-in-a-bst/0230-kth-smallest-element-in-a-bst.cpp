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
stack<Node*>asc;
Node* getsmall(){
    if(asc.empty()){
        return null;
    }
    Node* small = asc.top();
    asc.pop();
    Node* rightchild = small->right;
    while(rightchild){
        asc.push(rightchild);
        rightchild = rightchild->left;
    }
    return small;
}
    int kthSmallest(TreeNode* root, int k) {
        if(root == null){
            return -1;
        }

        Node* t = root;
        while(t){
            asc.push(t);
            t =t->left;
        }
        while(k>0){
            t = getsmall();
            
            k--;
        if(k == 0){
            return t->data;
        }
        }
    return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna