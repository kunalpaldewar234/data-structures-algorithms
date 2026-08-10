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
vector<vector<int>>res;
void fun(Node* root,int sum ,vector<int>&diary,int targetsum){
    if(root == null){
        return;
    }
    sum  += root->data;
    diary.push_back(root->data);

    if(root->left == null && root->right == null){
        if(sum == targetsum){
            res.push_back(diary);
           
        }
    }
    fun(root->left,sum,diary,targetsum);
    fun(root->right,sum,diary,targetsum);
    diary.pop_back();
    return;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetsum) {
        int sum =0;
        vector<int>diary;
        fun(root,sum,diary,targetsum);
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna