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
stack<Node*>asc;
stack<Node*>desc;
Node* getsmall(){
    if(asc.empty()){
        return null;
    }
    Node* small = asc.top();
    asc.pop();
    Node* rightchild = small->right;
    while(rightchild){
        asc.push(rightchild);
        rightchild =  rightchild->left;     // sare left element push karo
    }
    return small;
}
Node* getbig(){
    if(desc.empty()){
        return null;
    }
    Node* big = desc.top();
    desc.pop();
    Node* leftchild =big->left;
    while(leftchild){
        desc.push(leftchild);
        leftchild = leftchild->right;
    }
    return big;
}

    bool findTarget(TreeNode* root, int k) {
        if(root == null){
            return false;
        }
        Node*t = root;
        while(t){
            asc.push(t);
            t = t->left;
        }
        t = root;
        while(t){
            desc.push(t);
            t = t->right;
        }
        Node* i = getsmall();
        Node* j = getbig();
        while((i!= null && j!= null) && i != j && (i->data <= j->data)){
            int sum = i->data +j->data;
            if(sum == k){
                return true;
            }else if(sum > k){
                j = getbig();
            }else{
                i = getsmall();
            }
        }
        return false;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna