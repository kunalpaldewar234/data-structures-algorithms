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
int idx = 0;
unordered_map<int,int>in;
Node* fun(vector<int>&preorder,int low,int high){
    if(low > high) {
        return null;
    }
    Node* node = new Node(preorder[idx]);
    idx++;
    int id = in[node->data];
    node->left = fun(preorder,low,id-1);
    node->right = fun(preorder,id+1,high);
    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]] = i;
        }

    return fun(preorder,0,inorder.size()-1);
    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna