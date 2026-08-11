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
int galat = 0;
Node* g1first = null;
Node* g1second = null;
Node* g2first = null;
Node* g2second = null;
Node* prev = null;
void fun(Node* root){
    if(root == null){
        return;
    }
    fun(root->left);
    if(prev == null){
        prev = root;
    }else{
        if(prev->data > root->data){
            if(galat ==0 ){
                g1first = prev;
                g1second = root;
                galat++;
            }else{
                g2first = prev;
                g2second = root;
                galat++;
            }
        }
        prev = root;
    }
    fun(root->right);
    return;
}
    void recoverTree(TreeNode* root) {
        fun(root);
        if(galat == 1){
            swap(g1first->data,g1second->data);
        }else if (galat == 2){
            swap(g1first->data,g2second->data);
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna