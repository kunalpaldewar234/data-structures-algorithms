/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
# define Node ListNode
# define null nullptr
struct cmp{
    bool operator()(Node* a,Node* b){
        return a->val > b->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node* ,vector<Node*>,cmp>pq;
        int n = lists.size();
        Node * dummy =  new Node(-1);
        Node* tail = dummy;
        for(int i=0;i<n;i++){
            if (lists[i] != NULL) {
                pq.push(lists[i]);
             }
        }
        while(!pq.empty()){
            Node* n = pq.top();
            pq.pop();
            int v = n->val;
            tail->next = n;
            tail = tail->next;
            if(n->next != null){
                pq.push(n->next);
            }
        }
        tail->next = nullptr;
        return dummy->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna