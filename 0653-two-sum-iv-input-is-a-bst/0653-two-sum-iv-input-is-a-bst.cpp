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
void inorder(Node* root,vector<int>&res){
    if(root == null){
        return;
    }
    inorder(root->left,res);
    res.push_back(root->data);
    inorder(root->right,res);

}
bool fun(vector<int>&res,int k){
    int n = res.size();
    int low = 0;
    int high = n-1;
    while(low < high){
        int sum = res[low]+res[high];
        if(sum == k){
            return true;
        }else if(sum > k){
            high--;
        }else{
            low++;
        }
    }
    return false;
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>res;
        inorder(root,res);
        return fun(res,k);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna