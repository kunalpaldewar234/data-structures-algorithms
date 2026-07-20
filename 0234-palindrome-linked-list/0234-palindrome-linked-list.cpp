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

    Node*  reverse(Node*  head){


         Node* prev = null;
        Node* curr = head;

        while(curr != null){
            Node * nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr= nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        if(head == null || head->next == null){
            return true;
        }

        Node* slow = head;
        Node* fast = head;

        while( fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        Node * secondhalf = reverse(slow->next);

        Node* temp = secondhalf;
        Node* first = head;

        while(temp){
            if(temp->data  != first->data){
                return false;
            }
            temp = temp->next;
            first = first->next;
        }
        return true;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna