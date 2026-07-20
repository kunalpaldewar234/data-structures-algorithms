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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == null){
            return null;
        }

        Node* last = head;
        int len = 1;
        while(last->next != null){
           last =  last->next;
           len++; 
        }
        k = k%len;
        if(k==0){
            return head;
        }
        int pos = (len-k);
        int count =1;
        Node* temp = head;
        while(temp!= null){
            if(count == pos){
                break;
            }
            count++;
            temp = temp->next;
        }

        last->next = head;
        Node* res = temp->next;
        temp->next = null;
        return res;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna