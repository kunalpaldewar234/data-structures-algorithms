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
vector<int>fun(Node * node,vector<int>&res){
    if(node == null){
        return res;
    }

    fun(node->left,res);
    res.push_back(node->data);
    fun(node->right,res);
    return res;

}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int>res;
    fun(root,res);
    return res;  
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna