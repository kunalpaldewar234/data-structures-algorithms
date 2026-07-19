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
public:
    #define Node ListNode
    #define null nullptr
    #define data val

    ListNode* removeElements(ListNode* head, int val) {
        Node * curr = head;
        Node * prev = null;

        while(curr != null){
            if(curr->data == val){
                if(prev){
                    prev->next = curr->next;
                }else{
                    head  = curr->next;
                }
                
                curr = curr->next;
            }else{
                prev = curr;
                curr = curr->next;
            }

        }
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna